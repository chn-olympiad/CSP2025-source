#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int k,n,ans;
int a[N];
int b[N],t;
struct lsj
{
	int l,r;
}c[N];
int g=0;
void dfs(int l,int r)
{
	if(l>r||l>n||r>n)return;
	int s=a[l];
	for(int i=l+1;i<=r;i++)
	{
		s^=a[i];
	}
	if(s==k)
	{
		g++;
		c[g].l=l;
		c[g].r=r;
	}
	dfs(l+1,r);
	dfs(l,r+1);
}
bool cmp(lsj x,lsj y)
{
	if(x.r!=y.r)return x.r<y.r;
	return x.l<y.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	bool f=1;
	if(k>1)f=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)f=0;
		if(a[i]==1)cnt++;
	}
	if(f)
	{
		cout<<cnt;
		return 0;
	}
	dfs(1,1);
	for(int i=1;i<=g;i++)
	{
		if(c[i].l<=c[i-1].r)continue;
		ans++;
	}
	cout<<ans;
	return 0;
}