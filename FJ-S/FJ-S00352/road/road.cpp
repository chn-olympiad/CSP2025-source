#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int N = 1e6+10,N1 = 1e4+10;
ll n,m,k,fa[2*N],edi,brip[N];
ll aij[N],cij[N];
bool paj[12];
struct node
{
	ll v,w,elist;
};
struct bridge
{
	ll u,v,w;
};
bridge edge[N];
vector<node> map[3*N];
ll find(ll x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void Union(ll x,ll y)
{
	x = find(x),y = find(y);
	fa[x] = fa[y];
}
bool check(ll x,ll y)
{
	fa[x] = find(x);
	fa[y] = find(y);
	return fa[x] == fa[y];
}
bool cmp(bridge x1,bridge x2)
{
	return x1.w < x2.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= 3*n;i++) fa[i] = i;
	for(int i = 1;i <= m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		map[a].push_back({b,c,edi+1});
		map[b].push_back({a,c,edi+1});
		edi++;
		edge[edi] = {a,b,c};
	}
	for(int i = k+1;i <= n;i++) 
	{
		map[i].push_back({i+n,0,edi+1});
		map[i+n].push_back({i,0,edi+1});
		edi++;
		edge[edi]={i,i+n,0};
	}
	for(int i = 1;i <= k;i++)
	{
		cin>>cij[i];
		for(int j = 1;j <= n;j++)
			cin>>aij[j];
		for(int j = 1;j <= n;j++)
		{
			if(i == j) 
			{
				aij[j] = aij[j]+cij[i];	
				map[i+n].push_back({i,aij[j],edi+1});
				map[i].push_back({i+n,aij[j],edi+1});
				edi++;
				edge[edi] = {i,i+n,aij[j]};
			}
			else
			{
				map[i+n].push_back({j+n,aij[j],edi+1});
				map[j+n].push_back({i+n,aij[j],edi+1});
				edi++;
				edge[edi] = {i+n,j+n,aij[j]};	
			}
		}
	}
	sort(edge+1,edge+edi+1,cmp);
	ll cost = 0;
//	for(int i = 1;i <= edi;i++) cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
//	cout<<"_______________________"<<endl;
	for(int i = 1;i <= edi;i++) 
	{
		//cout<<check(edge[i].u,edge[i].v)<<endl;
		if(check(edge[i].u,edge[i].v)) continue;
		//cout<<fa[edge[i].u]<<" "<<fa[edge[i].v]<<endl;
		Union(edge[i].u,edge[i].v);
		if(edge[i].u != edge[i].v-n&&edge[i].u != edge[i].v + n) Union(edge[i].u,edge[i].v);
		if(edge[i].v%n==0&&edge[i].u%n != 0) Union(edge[i].u,edge[i].v+n);
		else if(edge[i].u%n==0&&edge[i].v%n != 0) Union(edge[i].u+n,edge[i].v);
		else if(edge[i].u%n==0&&edge[i].v%n == 0) Union(edge[i].u+n,edge[i].v+n);
		//cout<<fa[edge[i].u]<<" "<<fa[edge[i].v]<<endl;
//		cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
		cost += edge[i].w;
	}
	cout<<cost;
	return 0;
}
