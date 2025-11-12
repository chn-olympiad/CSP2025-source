#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mo=998244353,ans;
int dp[505][505],li[505];
int a[12];
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>li[i];
	if(n<=10)
	{
		for(int i=1;i<=n;i++)a[i]=i;
		int cnt=0;
		do{
			cnt++;
			int now=0,res=0;
			for(int i=1;i<=n;i++)
			{
				if(now<li[a[i]]&&s[i]=='1')res++;
				else now++;
			}
			ans+=(res>=m);
		}while(next_permutation(a+1,a+n+1));
		cout<<ans;return 0;
	}
	ans=1;
	for(int i=2;i<=n;i++)
		ans=ans*i%mo;
	cout<<ans;
	return 0;
}
