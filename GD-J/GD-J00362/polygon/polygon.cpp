#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int m=998244353;
ll n,a[5005],d[5005],cnt,summ,maxx,lmax;
void dfs(ll x,ll y)
{
	if(x>n)	return ;
	if(y<=1)
	{
		if(summ>2*maxx)	cnt++;
		cnt%=m;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		summ+=a[x];
		lmax=maxx;
		maxx=max(maxx,a[x]);
		dfs(x+i,y-1);
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)	d[i]=d[i-1]+a[i];
	for(int i=3;i<=n;i++)
	{
		summ=0;
		maxx=0;
		dfs(1,i);
	}
	cout<<cnt;
	//084 Company!
	
	return 0;
} 
