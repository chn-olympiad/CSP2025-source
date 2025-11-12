#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long n,a[5010],df,b[5010],cf[5010],kkk;
void dfs(int c,int v,int k)
{
	if(v>k*2)
	{
		kkk++;
		kkk%=Mod;
	} 
	for(int i=c-1;i>=1;i--)
	{
		if(v+b[i]>k*2 && cf[i]==0) 
		{
			cf[i]=1;
			dfs(i,v+a[i],k);
			cf[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	for(int i=n;i>=3;i--)
	{
		kkk=0;
		dfs(i,a[i],a[i]);
		df+=kkk;
		df%=Mod;
	}
	cout<<df;
	fclose(stdin);
	fclose(stdout);
	return 0;
}  
/*
obuhui!!!
*/ 
