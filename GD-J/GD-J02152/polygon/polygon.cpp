#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sz[5010],pd[2500000];
ll n;
ll bfs(ll cnt,ll maxn,ll i,ll jsq)
{
	if(i>n+1) return 0;
//	if(cnt>2*maxn&&jsq>2) cout<<'*';
//	std::cout<<cnt<<' '<<maxn<<' '<<i<<' '<<jsq<<endl;
	if(cnt>2*maxn&&jsq>2) 
	{
		if(pd[cnt]==0) 
		{
			pd[cnt]=i;
			return bfs(cnt+sz[i],sz[i],i+1,jsq+1)%998244353+bfs(cnt,maxn,i+1,jsq)%998244353+1;
		}
		else 
		{
			if(sz[i]==sz[pd[cnt]]) return bfs(cnt+sz[i],sz[i],i+1,jsq+1)+bfs(cnt,maxn,i+1,jsq)+1;
			else return bfs(cnt+sz[i],sz[i],i+1,jsq+1)+bfs(cnt,maxn,i+1,jsq);
		}
	}
	return bfs(cnt+sz[i],sz[i],i+1,jsq+1)+bfs(cnt,maxn,i+1,jsq);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>sz[i];
	}
	cout<<bfs(0,0,1,0)%998244353;
	return 0;
}

