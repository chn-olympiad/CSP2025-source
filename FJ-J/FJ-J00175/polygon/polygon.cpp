#include<bits/stdc++.h>
using namespace std;
int a[5005],shu[5005],n,k;
long long ans;
int result(int ci)
{
	int sum=0,maxn=-1;
	for(int i=1;i<=ci;i++)
	{
		maxn=max(maxn,shu[i]);
		sum+=shu[i];
	}
	if(sum>maxn*2)return 1;
	else return 0;
}
void dfs(int cnt,int ci)
{	
	if(ci-1==k&&result(ci))
	{
		ans=(ans+1)%998244353;
		return ;
	}
	for(int i=cnt;i<=n;i++)
	{
		shu[ci]=a[i];
		dfs(i+1,ci+1);
		shu[ci]=0;
	}
	return ;
}
int main(){
	freopen("polygon.in ","r",stdin);
	freopen("polygon.out ","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		k=i;
		for(int j=1;j<=n;j++)
		{
			shu[1]=a[j];
			dfs(j+1,2);
		}
	}
	cout<<ans;
	return 0;
}