#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll n,a[5010],path[5010],way[5010],ans;
bool flag[(1<<20)+10],vis[5010];
bool check(ll len)
{
	if(len < 3) return 0;
	ll sum = 0,max = -1,k = 0;
	for(ll i = 1;i < len;i++)
	{
		k = k + (1<<way[i]);
		sum += path[i];
		if(path[i] > max) max = path[i];
	}
	if(flag[k]) return 0;
	flag[k] = 1;
	if(sum > 2*max) return 1;
	else return 0;
}
void dfs(int step,int pi)
{
	if(check(pi)) 
	{
		ans = (ans+1)%mod;
		/*for(int i = 1;i < pi;i++)
			cout<<path[i]<<" ";
		cout<<endl;*/
	}
	if(step == n) return;
	for(int i = 1;i <= n;i++)
	{
		if(vis[i]) continue;
		path[pi] = a[i];
		way[pi] = i;
		vis[i] = 1;
		dfs(step+1,pi+1);
		path[pi] = 0;
		way[pi] = 0;
		vis[i] = 0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	dfs(1,1);
	cout<<ans;
	return 0;
}
/*
2	3	4
		5
*/
