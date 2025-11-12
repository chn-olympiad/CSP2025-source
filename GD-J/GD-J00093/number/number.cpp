#include<bits/stdc++.h>
using namespace std;
#define int long long //<------------------------
int n;
char s[1000010];
int cnt[11];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>(s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if('0'<=s[i]&&s[i]<='9') cnt[s[i]-'0']++;
	}
	bool flag=0;
	for(int i=9;i>=0;i--)
	{
		if(!cnt[i]) continue;
		if(!flag&&i==0) return cout<<"0",0;
		flag=1;
		while(cnt[i]--) cout<<i;
	}
	return 0;
}
/*

shen shou bao you

*/
