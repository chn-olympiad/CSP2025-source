#include<bits/stdc++.h>
using namespace std;
long long q,n;
struct add{
	long long l[4];
}a[100005],t[4][4][100005];
long long f[4][4][100005];
long long ff[100005];
bool cmp(add k,add kk)
{
	long long t=1;
	if(k.l[2]>k.l[1]&&k.l[2]>k.l[3])
	{
		t=2;
	}
	if(k.l[3]>k.l[1]&&k.l[3]>k.l[2])
	{
		t=3;
	}
	long long m=1;
	if(kk.l[2]>kk.l[1]&&kk.l[2]>k.l[3])
	{
		m=2;
	}
	if(kk.l[3]>kk.l[1]&&kk.l[3]>kk.l[2])
	{
		m=3;
	}
	return k.l[t]>kk.l[m];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].l[1],&a[i].l[2],&a[i].l[3]);
			for(int j=1;j<=3;j++)
			{
				f[1][j][i]=f[2][j][i]=f[3][j][i]=0;
				t[1][j][i]=t[2][j][i]=t[3][j][i]={0,0,0,0};
			}
		}
		sort(a+1,a+1+n,cmp);
		long long m=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				f[j][0][i]=1e9;
				for(int o=1;o<=3;o++)
				for(int p=1;p<=3;p++)
				for(int k=1;k<=3;k++)
				{
					if(t[p][k][i-1].l[j]<m)
					{
						if(f[j][o][i]<f[p][k][i-1]+a[i].l[j]&&f[p][k][i-1]+a[i].l[j]<f[j][o-1][i])
						{
							f[j][o][i]=f[p][k][i-1]+a[i].l[j];
							t[j][o][i]=t[p][k][i-1];
							t[j][o][i].l[j]++;
						}
					}
				}
			}
		}
		long long ans=0;
		//for(int j=1;j<=n;j++)
		//{
			for(int i=1;i<=3;i++)
			{
				//cout<<f[1][i][j]<<' '<<f[2][i][j]<<' '<<f[3][i][j]<<'\n';
				ans=max(f[1][i][n],ans);
				ans=max(f[2][i][n],ans);
				ans=max(f[3][i][n],ans);
			}
			//cout<<'\n';
		//}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
 3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0
 */
