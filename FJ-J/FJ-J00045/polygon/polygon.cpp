#include<bits/stdc++.h>
using namespace std;
int n,k,a[5001],maxx=0;
long long cunn[5001],summ=0,modd=998244353;
void dfs(int step,long long zhi,int s)
{
	long long maxx2=maxx;
	if(s==2)
	summ=(summ+(cunn[min(maxx2,zhi-1)]-cunn[a[step]])%modd)%modd;
	for(int i=step+1;i<n;i++)
	{
		dfs(i,zhi+a[i],min(s+1,2));
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	cunn[a[i]]++;
    	maxx=max(maxx,a[i]);
	}
	for(int i=2;i<=maxx;i++)
	cunn[i]+=cunn[i-1];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
	{
	long long p=a[i];
	dfs(i,p,1);
	}
	cout<<summ;
	return 0;
}
