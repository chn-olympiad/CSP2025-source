#include<bits/stdc++.h>
using namespace std;
int a[5005],x[5005],n;long long ans;bool allone=true;
void fun(int step,long long sum,int las)
{
	if(step==n+1)return ;
	if(step>=3&&sum>a[las]*2)
	{
		ans++;
		ans%=998244353;
	}
	for(int i=las+1;i<=n;i++)
	{
		x[step]=a[i];
		fun(step+1,sum+a[i],i);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==0||n==1||n==2){cout<<0;return 0;}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)allone=false; 
	}
	if(allone)
	{
		cout<<((n-2+1)*(n-2)/2)%998244353;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n==3)if(a[1]+a[2]+a[3]>a[3]*2){cout<<1;return 0;}
	fun(0,0,0);
	cout<<ans%998244353;
	return 0;
 } 
