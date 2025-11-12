#include<bits/stdc++.h>
using namespace std;
int n,s[5001],c[5001],ans,ant;
void dfs(int k,int j);
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>s[i];
	}
	sort(s+1,s+1+n);
	if(n<3)
	{
		printf("0");
		return 0;
	 } 
	if(n==3) 
	{
		if((s[1]+s[2]+s[3])>(2*s[3])) printf("1");
		else printf("0");
		return 0;
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
void dfs(int k,int j)
{
	if(k>3)
	{
		ant=0;
		for(int i=1;i<k;i++) ant+=c[i];
		if(ant>2*c[k-1]) ans++;
	}			
	for(int i=j;i<=n;i++)
	{
		c[k]=s[i];
		dfs(k+1,i+1);
		ant-=s[i];
	}
}
