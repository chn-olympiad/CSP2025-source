#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
long long cd[N],n,ans,xz[N];
void pd(int top)
{
	long long ma=0,h=0;
	for(int i=1;i<=top;i++)
	{
		if(xz[i]>ma)
		{
			ma=xz[i];
		}
		h+=xz[i];
	}
	if(h>ma*2)
	{
		ans++;
		ans%=998244353;
	}
	return ;
}
void dfs(int ma,int c,int x)
{
	if(c>ma)
	{
		pd(ma);
		return ;
	}
	for(int i=x+1;i<=n;i++)
	{
		xz[c]=cd[i];
		dfs(ma,c+1,i);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>cd[i];
	}
	for(int i=3;i<=n;i++)
	{
		dfs(i,1,0);
	}
	cout<<ans;
	return 0;
}