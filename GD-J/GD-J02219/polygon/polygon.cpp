#include<bits/stdc++.h>
using ll = long long;
using namespace std;
ll ans,md = 998244353;
int n,mx,sum;
struct node{
	int val,vis;
}a[5005];
set<vector<int> >st;
bool cmp(node a,node b)
{
	if(a.vis && b.vis)return a.val > b.val;
	return a.vis > b.vis;
}
void dfs(int sum,int mx,int num)
{
	if(num < 3)return ;
	if(sum > 2*mx)
	{
		vector<int>f;
		for(int i = 1;i <= n;i++)
		{
			if(a[i].vis)f.push_back(i);
		}
		st.insert(f);
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++)
	{
		a[i].vis = 0;
		if(i == 1)dfs(sum - a[i].val,a[2].val,num-1);
		else dfs(sum - a[i].val,a[1].val,num-1);
		a[i].vis = 1;
	}
}
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i].val);
		sum += a[i].val;
		mx = max(mx,a[i].val);
		a[i].vis = 1;
	}
	dfs(sum,mx,n);
	printf("%lld",st.size()%md);
	return 0;
}

