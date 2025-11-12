#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001],amax=0;
int M=998244353;
int an=0;
void dfs(int k,int sum,int max0,int how)
{
	if(k>n||how>n)return;
	dfs(k+1,sum,max0,how);
	if(sum>a[k]&&how>=2)
	{
		//cout<<sum+a[k]<<' '<<max(a[k],max0)<<'\n';
		an=(an+1)%M;
	}
	dfs(k+1,sum+a[k],max(a[k],max0),how+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		amax=max(amax,a[i]);
	}
    a[n+1]=0; 
	//1~3
	if(n<3){cout<<0;return 0;}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*amax){cout<<1;return 0;}
		else {cout<<0;return 0;}
	}
	//15~20
	if(amax==1)
	{
		int ans=1;
		for(int i=1;i<=n;i++)ans=(ans*2)%M;
		ans=(ans-1-n-(n-1)*n/2)%M;
		cout<<ans;return 0;
	}
	//4~10
	dfs(1,0,0,0);
	cout<<an;
	return 0;
}
