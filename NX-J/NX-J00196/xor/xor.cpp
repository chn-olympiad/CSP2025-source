#include<bits/stdc++.h>
#define N 500005
#define M 100005
#define int long long
using namespace std;
int n,m,a[N],ma,mi=100000000,dp[N],s[N],ans;
signed main()
{
	freopen("xor4.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
		s[i]=s[i-1]^a[i];
	}
	if(ma==1&&mi==1)
	{
		cout<<n/2;
		return 0;
	}
	for(int id=1;id<=n;id++)
	{
		if(n-id+1<=ans)break;
		int cnt=0;
		for(int i=id;i<=n;i++)
		{
			int cnt2=0,macnt=0;
			for(int k=i;k<=n;k++)
			{
				for(int j=k;j<=n;j++)
				{
					int tt=s[j]^s[i-1];
					if(tt==m)
					{
						i=j;
						cnt2++;
						break;
					}
				}
			}
			macnt=max(macnt,cnt2);
			cnt=max(cnt,macnt);
			cnt2=0;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
/*
ji xu zheng huo
(hua shuo geany shen mi de zhu shi xi tong za hui shi a wei!
//freopen//freopen//freopen//freopen//freopen//freopen
*/
