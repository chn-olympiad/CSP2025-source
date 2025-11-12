#include<bits/stdc++.h>
#define int long long
using namespace std;

int T,n,ans,A,x[100001],y[100001],z[100001],f[201][201][201];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i) cin>>x[i]>>y[i]>>z[i];
		for(int i=1;i<=n;++i) if(y[i]==0&&z[i]==0) ++A;
		if(A==n)
		{
			sort(x+1,x+n+1);
			for(int i=n;i>=n/2+1;--i) ans+=x[i];
			cout<<ans<<endl;
			return 0;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=min(i,n/2);++j)
			{
				for(int k=0;k<=min(i-j,n/2);++k)
				{
					if(i-j-k>n/2) continue;
					if(j!=0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+x[i]);
					if(k!=0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+y[i]);
					if(i-j-k!=0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+z[i]);
					ans=max(ans,f[i][j][k]);
				}
			}
		}
		for(int i=1;i<=n;++i) for(int j=0;j<=i;++j) for(int k=0;k<=i-j;++k) f[i][j][k]=0;
		cout<<ans<<"\n";
	}
	return 0;
}

/*
Sakura最好了（划掉）
*/





