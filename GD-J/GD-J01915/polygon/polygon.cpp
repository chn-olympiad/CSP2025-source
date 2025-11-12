#include<bits/stdc++.h>
using namespace std;
int n,i,ans,anss,ff,a[114514],f[114514];
void dfs(int k,int maxx,int sum)
{
	if(k>i)
	{
		if(sum>2*maxx) ans++;
		return;
	}
	for(int j=1;j<=n;j++) if(!f[j]) f[j]=1,dfs(k+1,max(maxx,a[j]),sum+a[j]),f[j]=0;
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) ff=1;
	}
	for(i=3;i<=n;i++)
	{
		ans=0;
		dfs(1,0,0);
		for(int j=1;j<=n;j++) f[j]=0;
		for(int j=1;j<=i;j++) ans/=j;
		anss+=ans;
	}
	cout<<anss;
}
