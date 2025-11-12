#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6+10;
const int INF = 0x3f3f3f3f;
//1s 512mb number
string s;
char ans[N];
int cnt[20];
int pos;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9') cnt[s[i]-'0']++;
		//cout<<'0'-s[i]<<endl;
	}
	for(int i=9;i>=0;i--)
	{
		while(cnt[i]) 
		{
			ans[pos++] = '0'+i;
			cnt[i]--;
		}
	}
	cout<<ans;
}

