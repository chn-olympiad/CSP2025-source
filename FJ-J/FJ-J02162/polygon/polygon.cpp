#include<iostream>
#include<algorithm>
using namespace std;
int n,a[6000],di[6000],maxn=-1;
long long s=0,sum=0;
void dfs(long long st,int ma,long long su,long long eg)
{
	if(eg==0)
	{
		if(su>ma*2)s=(s+1)%998244353;
		return;
	}
	for(int i=st;i<=n;i++)
	{
		dfs(i+1,max(ma,a[i]),su+a[i],eg-1);
	}
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
		di[i]=di[i-1]+a[i];
	}
	for(int i=3;i<=n;i++)dfs(1,-1,0,i);
	cout<<s;
	return 0;
}
