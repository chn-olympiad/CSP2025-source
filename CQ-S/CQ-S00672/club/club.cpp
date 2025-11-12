#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 100010
#define inf 0x3f3f3f3f3f3f3f3f
int t,n,ans;
int a[maxn][3],aa[maxn];
bool ck_a()
{
	int mx=0;
	for(int i=1;i<=n;++i) mx=max({mx,a[i][2],a[i][3]});
	return mx==0;
}
bool ck_b()
{
	int mx=0;
	for(int i=1;i<=n;++i) mx=max(mx,a[i][3]);
	return mx==0;
}
vector<int>v;
int f[1010][1010];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=3;++j) cin>>a[i][j];
		}
		if(ck_a())
		{
			for(int i=1;i<=n;++i)
			{
				aa[i]=a[i][1];
			}
			sort(aa+1,aa+n+1,greater<int>());
			for(int i=1;i<=(n>>1);++i)
			{
				ans+=aa[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		if(ck_b())
		{
			v.clear();
			for(int i=1;i<=n;++i) ans+=a[i][1];
			for(int i=1;i<=n;++i) v.push_back(a[i][2]-a[i][1]);
			sort(v.begin(),v.end(),greater<int>());
			for(int i=0;i<(n>>1);++i)
			{
				ans+=v[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		memset(f,0,sizeof f);
		for(int i=1;i<=n;++i) 
		{
			for(int j=min(i,n>>1);j>=0;--j)
			{
				for(int k=min(n>>1,i-j);k>=0;--k)
				{
					if(j+k!=i)
					{
						if(k&&j)f[j][k]=max({f[j][k-1]+a[i][2],f[j-1][k]+a[i][1],f[j][k]+a[i][3]});
						else if(k)
						f[j][k]=max({f[j][k-1]+a[i][2],f[j][k]+a[i][3]});
						else if(j)
						f[j][k]=max({f[j-1][k]+a[i][1],f[j][k]+a[i][3]});
						else 
						f[j][k]+=a[i][3];
					}
					else
					{
						if(k&&j)f[j][k]=max({f[j][k-1]+a[i][2],f[j-1][k]+a[i][1]});
						else if(k)
						f[j][k]=max({f[j][k-1]+a[i][2]});
						else if(j)
						f[j][k]=max({f[j-1][k]+a[i][1]});
						
					}
				}
			}
		}
		for(int i=0;i<=(n>>1);++i)
		{
			for(int j=(n>>1)-i;j<=(n>>1);++j) ans=max(ans,f[i][j]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
