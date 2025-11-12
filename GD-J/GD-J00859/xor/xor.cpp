#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,k;
int k0ans,k1ans,ans,t;bool ts1;
void fun(int q,int e,int t)
{
		ans=max(ans,t);
		long long sum=0;
		for(int i=q;i<=e;i++)
			sum=(a[i]^sum);
		if(sum==k)
		{
			fun(e+1,e+1,t+1);
//			if(e+1<=n)fun(q,e+1,t);
//			else if(q+1<=n&&q+1<=e)fun(q+1,e,t);
//			else return ;
		}
		if(sum<k)
			if(e+1<=n)fun(q,e+1,t);
			else return ;
		if(sum>k)
			if(q+1<=n)fun(q+1,e,t);
			else return ;
		if(q==n&&e==n)return ;
	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==1)ts1=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(k==0&&a[i]==0)k0ans++;
		if(a[i]!=1)ts1=false;
		if(a[i]==1)k1ans++;
	}
	if(k==0){cout<<k0ans;return 0;}
	if(ts1){cout<<k1ans;return 0;}
	fun(1,1,0);cout<<ans; 
	return 0;
}
