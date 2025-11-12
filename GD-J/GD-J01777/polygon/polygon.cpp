#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
const int mod=998244353;
int n,a[5005];
int ans;
int s[5005],t,su;
bool cmp(int x,int y)
{
	return x>y;
}
int ksm(int s,int ko)
{
	t=s;
	su=1;
	while(ko>0)
	{
		if(ko%2==1)su=(su*t)%mod;
		t=t*t%mod;
		ko/=2;
	}
	return su;
}
void dfs(int k,int sum,int m,int x)
{
	if(x+n-k+1<3)return;
	if(k>n)
	{
		if(sum>m*2&&x>=3)ans=(ans+1)%mod;
		return;
	}
	if(sum>2*m&&x>=3)
	{
		//t=pow(2,n-k+1)*1ll;
		ans=(ans+ksm(2,n-k+1))%mod;
		//cout<<ans<<"\n";
		return;
	}
	if(x==0)t=a[k];
	else t=m;
	if(sum+s[n]-s[k-1]>t*2)dfs(k+1,sum+a[k],t,x+1);
	if(!(x>=1&&s[n]-s[k]+sum<=2*m))dfs(k+1,sum,m,x);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i]; 
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
//DFS骗分法保佑我 ！！！ 
