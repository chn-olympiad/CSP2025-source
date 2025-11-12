#include<bits/stdc++.h>
using namespace std;
int a,b=0,c,d,e,ma;
int x[10000];
bool y[10000];
void dfs(int s,int be,int ma,int n)
{
	for(int i=be;i<=a;i=i+1)
	{
		if(y[i]==0)
		{
			y[i]=1;
			s=s+x[i];
			if(ma<x[i])
			{
				ma=x[i];
			}
			if(s>ma*2 && n>=3)
			{
				b=b+1;
				b=b%998244353;
			}
			dfs(s,i+1,ma,n+1);
			y[i]=0;
			s=s-x[i];
		}
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i=i+1)
	{
		cin>>x[i];
	}
	sort(x+1,x+a+1);
	dfs(0,1,0,0);
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}