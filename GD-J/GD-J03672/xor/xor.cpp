#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005][3],ans,x,y,sum;
struct T
{
	long long l,r;
}
c[500005];
void f(long long l,long long r)
{
	long long p=a[l];
	for(int i=l+1;i<=r;i++)
	{
		p=p^a[i];
	}
	if(p==m) 
	{
		sum++;
		c[sum].l=l;
		c[sum].r=r;
	}
} 
bool cmp(T x,T y)
{
	if(x.l!=y.l) return x.l<y.l;
	return x.r<y.r;
}
void dfs(long long x,long long y)
{
	for(int i=x+1;i<=sum;i++)
	{
		if(c[x].r<c[i].l) 
		{
			dfs(i,y+1); 
			break;
		}
	}
	ans=max(ans,y);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			x++;
			b[x][1]=i;
			b[x][2]=j;
		}
	}
	for(int i=1;i<=x;i++)
	{
		f(b[i][1],b[i][2]);
	}
	sort(c+1,c+sum+1,cmp);
	for(int i=1;i<sum;i++)
	{
		dfs(i,1);
	}
	cout<<ans;
	return 0;
}
