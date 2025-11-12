#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
int T;
int n;
ll a[N][3];
int get_mx(int i)
{
	int mx=max(max(a[i][0],a[i][1]),a[i][2]);
	for(int j=0;j<=2;++j)
	{
		if(a[i][j]==mx)
			return j;
	}
}
void work()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
	}
	int num[3];
	ll res=0;
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;++i)
	{
		++num[get_mx(i)];
		res+=a[i][get_mx(i)];
	}
	int id=0;
	for(int i=0;i<=2;++i)
	{
		if(num[i]>num[id])
		{
			id=i;
		}
	}
	if(num[id]<=n/2)
	{
		printf("%lld\n",res);
		return ;
	}
	vector<ll> p;
	for(int i=1;i<=n;++i)
	{
		if(get_mx(i)!=id)
			continue ;
		swap(a[i][0],a[i][id]);
		p.push_back(a[i][0]-max(a[i][1],a[i][2])); 
	}
	sort(p.begin(),p.end());
	for(int i=0;i<num[id]-n/2;++i)
	{
		res-=p[i];
	}
	printf("%lld\n",res);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		work();
	}
	return 0;	
} 












