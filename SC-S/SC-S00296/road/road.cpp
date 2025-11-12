#include <bits/stdc++.h>
#define ll long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
void init(vector<ll> &p)
{
	for(ll i=0;i<(ll)p.size();i++)
	{
		p[i]=i;
	}
	return ;
}
ll fd(ll x,vector<ll> &p)
{
	if(p[x]==x)
	{
		return x;
	}
	p[x]=fd(p[x],p);
	return p[x];
}
void un(ll a,ll b,vector<ll> &p)
{
	ll pa=fd(a,p),pb=fd(b,p);
	if(pa!=pb)
	{
		p[pb]=pa;
	}
	return ;
}
struct str
{
	ll be,to,val;
};
bool cmp(str a,str b)
{
	return a.val>b.val;
}
ll n,m,k;
vector<str> edge;
vector<ll> father;
ll Ke_Lu_Si_Ka_Er()
{
	ll cnt=0,sum=0;
	stable_sort(edge.begin(),edge.end(),cmp);
	while(!edge.empty())
	{
		if(fd(edge.back().be,father)!=fd(edge.back().to,father))
		{
			un(edge.back().be,edge.back().to,father);
			sum+=edge.back().val;
			cnt+=1;
		}
		edge.pop_back();
		if(sum==n-1)
		{
			break;
		}
	}
	if(sum==n-1)
	{
		return cnt;
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	father.resize(n);
	init(father);
	for(ll i=0,u,v,w;i<m;i++)
	{
		cin>>u>>v>>w;
		edge.push_back({u,v,w});
	}
	cout<<Ke_Lu_Si_Ka_Er();
	return 0;
}