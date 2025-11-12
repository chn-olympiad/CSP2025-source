#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
int n[1000010];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=1;
	for(int i=0;s[i];i++)
	{
		if(s[i]<='9' && s[i]>='0')
		{
			int x=s[i]-'0';
			n[cnt]=x;
			cnt++;
		}
	}
	sort(n+1,n+1+cnt);
	for(int i=cnt;i>1;i--)
	{
		cout<<n[i];
	}
	return 0; 
}
