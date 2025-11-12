#include<bits/stdc++.h>
using namespace std;
int a[10005],n,maxnn,maxn,maxll;
int DFS(int l,int ls,int maxl,int sum,int i)
{
	if(l<1)
	{
		if(sum>2*maxl)
		{
			maxnn++;
			return 0;
		}
	}
	return sum+DFS(l,ls,max(maxl,a[i]),sum+a[i],i+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		DFS(i,i,0,0,1);
		maxll+=maxn;
		maxn=0;
	}
	cout<<maxll;
	return 0;
}
