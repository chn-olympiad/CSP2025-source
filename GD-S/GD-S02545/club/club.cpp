#include<bits/stdc++.h>
#define LL long long
#define rep(i,a,b,g) for(LL i=a;i<=b;i+=g)
using namespace std;
LL n,a[100010][4],su[4],f[100010];
vector<LL>v[4];
multiset<LL>s;
void sol()
{
	cin>>n;
	LL mc,mst,tt;
	su[1]=su[2]=su[3]=0;
	v[1].clear();
	v[2].clear();
	v[3].clear();
	rep(i,1,n,1)
	{
		mc=0;
		rep(j,1,3,1)
		{
			scanf("%lld",&a[i][j]);
			mc=max(mc,a[i][j]);
		}
		f[i]=a[i][1]+a[i][2]+a[i][3]-(max(a[i][1],max(a[i][2],a[i][3]))+min(a[i][1],min(a[i][2],a[i][3])));
		if(mc==a[i][1])
		{
			v[1].push_back(i);
			su[1]+=mc;
			continue;
		}
		if(mc==a[i][2])
		{
			v[2].push_back(i);
			su[2]+=mc;
			continue;
		}
		if(mc==a[i][3])
		{
			v[3].push_back(i);
			su[3]+=mc;
			continue;
		}
	}
	if(max(v[1].size(),max(v[2].size(),v[3].size()))<=n/2)
	{
		cout<<su[1]+su[2]+su[3]<<'\n';
		return;
	}
	if(v[1].size()>n/2)mst=1;
	if(v[2].size()>n/2)mst=2;
	if(v[3].size()>n/2)mst=3;
	s.clear();
	for(LL i:v[mst])
	{
		s.insert(a[i][mst]-f[i]);
	}
	mc=0;
	tt=0;
	for(LL i:s)
	{
		mc+=i;
		tt++;
		if(tt==v[mst].size()-n/2)break;
	}
	cout<<su[1]+su[2]+su[3]-mc<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

//	freopen("you.have","cnt.broken++");
//	freopen("no.egg","cnt.broken==2");

	LL T;
	cin>>T;
	while(T--)sol();
	return 0;
}
