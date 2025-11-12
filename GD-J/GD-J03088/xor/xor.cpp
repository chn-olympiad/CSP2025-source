#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int V=3e6+5;
int n,k,a[N],s[N],dp[N];
vector<int>c[V];
bool vis[N];
struct node
{
	int l,r;
	friend bool operator<(node a,node b)
	{return a.r>b.r;}
};
priority_queue<node>q;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=0;i<n;i++)
		c[s[i]].push_back(i);
	for(int i=1;i<=n;i++)if(c[s[i]^k].size())
	{
		auto p=lower_bound(c[s[i]^k].begin(),c[s[i]^k].end(),i);
		if(p!=c[s[i]^k].begin())if(!vis[*prev(p)+1])
			q.push({*prev(p)+1,i}),vis[*prev(p)+1]=1;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+(a[i]==k);
		for(;!q.empty()&&q.top().r<i;q.pop());
		for(;!q.empty()&&q.top().r==i;q.pop())
			dp[i]=max(dp[i],dp[q.top().l-1]+1);
	}
	cout<<dp[n]<<endl;
	return 0;
}
