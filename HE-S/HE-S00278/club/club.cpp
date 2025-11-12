#include<bits/stdc++.h>
using namespace std;
int t,n,q[3];
long long ans;
struct node
{
	int a,b,c;
}f[100005];
void dfs(int p,long long s)
{
	if(p==n+1)
	{
		ans=max(ans,s);
		return;
	}
	if(q[0]<n/2)
		q[0]++,dfs(p+1,s+f[p].a),q[0]--;
	if(q[1]<n/2)
		q[1]++,dfs(p+1,s+f[p].b),q[1]--;
	if(q[2]<n/2)
		q[2]++,dfs(p+1,s+f[p].c),q[2]--;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		ans=0;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> f[i].a >> f[i].b >> f[i].c;
		dfs(1,0);
		cout << ans << '\n';
	}
	return 0;
}
