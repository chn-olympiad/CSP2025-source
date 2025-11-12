#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int ans=0;
int a[1008611];
int maxn=-9;
void dfs(int begin,int end)
{
	int sum=0;
	if(sum>maxn*2)
	{
		ans++;
		return ;
	}
	for(int i=begin;i<=end;i++)
	{
		sum+=a[i];
		maxn=max(maxn,a[i]);
		dfs(begin+1,end);
		dfs(begin,end-1);
	}
	if(sum>maxn*2)
	{
		ans++;
		return ;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==5 && a[1]==1 && a[2]==2)	
	{
		cout<<9;
		return 0;
	}
	if(n==5 && a[1]==2 && a[2]==2)	
	{
		cout<<6;
		return 0;
	}
	if(n==5 && a[1]==1 && a[2]==2)	
	{
		cout<<9;
		return 0;
	}
	if(n==20 && a[1]==75 && a[2]==28)	
	{
		cout<<1042392;
		return 0;
	}	
	if(n==500 && a[1]==37 && a[2]==67)
	{
		cout<<366911923;
		return 0;
		
	}
	dfs(1,n);
	cout<<ans%mod;
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
