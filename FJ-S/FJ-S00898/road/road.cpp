#include<bits/stdc++.h>
using namespace std;
#define INF=0x3f3f3f3f3f3f3f3f
#define int long long
vector<pair<int,int>>v[10010];
int a[100010],b[100010],c[100010];
int	z[100010],z1[100010],z2[100010],z3[100010],z4[100010]; 
int s[100010],ss[100010];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		v[a[i]].push_back({b[i],c[i]});
		v[b[i]].push_back({a[i],c[i]});
	}
	sort(c+1,c+1+n);
	int ans=0;
	ans+=c[n]+c[n-1];
	for(int i=1;i<=k;i++)
	{
		cin>>z[i]>>z1[i]>>z2[i]>>z3[i]>>z4[i];
		s[i]+=z[i]+z1[i]+z2[i]+z3[i]+z4[i];
	}
	sort(s+1,s+k+1);
	ans+=z1[k]+z2[k];
	cout<<ans<<endl;
	return 0;
} 
