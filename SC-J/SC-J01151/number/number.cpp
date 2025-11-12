#include<bits/stdc++.h>
#define N 15
#define LL long long
//#define int long long
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;

string s;
int cnt[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') cnt[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			cout<<i;
		}
	}
//	printf("\ntime:%.0lfms",(double)clock());
	return 0;
}//知颖你太美