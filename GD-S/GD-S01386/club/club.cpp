#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,INF=1e18;
ll a[N][5],w[N][5];
struct node{ll num,id;}b[5];
bool cmp(node a,node b){return a.num>b.num;} 
struct edge{ll x,c,id;friend bool operator<(edge a,edge b){return a.c>b.c;}};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		ll n;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			for(ll j=1;j<=3;j++)b[j]={a[i][j],j};
			sort(b+1,b+1+3,cmp);
			w[i][1]=b[1].id,w[i][2]=b[2].id,w[i][3]=b[3].id;
		}
		priority_queue<edge>s[5];
		for(ll i=1;i<=n;i++)s[w[i][1]].push({a[i][w[i][1]],a[i][w[i][1]]-a[i][w[i][2]],i});
		for(ll i=2;i<=3;i++)
		{
			while((ll)s[1].size()>n/2)
			{
				edge t=s[1].top();
				s[1].pop();
				s[w[t.id][i]].push({a[t.id][w[t.id][i]],a[t.id][w[t.id][i]-a[t.id][w[t.id][i+1]]],t.id});
			}
			while((ll)s[2].size()>n/2)
			{
				edge t=s[2].top();
				s[2].pop();
				s[w[t.id][i]].push({a[t.id][w[t.id][i]],a[t.id][w[t.id][i]]-a[t.id][w[t.id][i+1]],t.id});
			}
			while((ll)s[3].size()>n/2)
			{
				edge t=s[3].top();
				s[3].pop();
				s[w[t.id][i]].push({a[t.id][w[t.id][i]],a[t.id][w[t.id][i]]-a[t.id][w[t.id][i+1]],t.id});
			}
		}
		ll ans=0;
		while(!s[1].empty())ans+=s[1].top().x,s[1].pop();
		while(!s[2].empty())ans+=s[2].top().x,s[2].pop();
		while(!s[3].empty())ans+=s[3].top().x,s[3].pop();
		printf("%lld\n",ans);
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
Ren5Jie4Di4Ling5%
*/
