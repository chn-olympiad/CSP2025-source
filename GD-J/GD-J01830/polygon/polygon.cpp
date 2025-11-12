#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],num;
long long sum[5050][5050],maxx=-1,ans=0;
void dfs(int c)
{
	if(c>=n)return;
	int j;
	for(j=c+1;j<=n;j++)
	{
		sum[c][j]=a[j];
		for(int k=n-c;k<=j;k++)
			if(a[k]>maxx)maxx=a[k]*2;
		ans++;
		int numm=0;
		for(int k=1;k<=j;k++)numm+=sum[c][k];
		if(ans>=3&&numm>maxx)num++;
		dfs(j);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		sum[i][1]=i,maxx=-1,ans=0;
		dfs(i);
	}
	cout<<num-1;
	return 0;
}
