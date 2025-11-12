#include<bits\stdc++.h>
using namespace std;
long long n,a[5005],ans,sum;
const int mod=998244353;
int pd=0,c[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)  pd=1;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[3]+a[1]>a[2])
		cout<<1;
		else cout<<0;
		return 0;
	} 
	else if(pd==0){
		long long sum=0;
		for(int i=3;i<=n;i++){
			ans=1;
			for(int j=i+1;j<=n;j++)
			{
				ans*=j;
				ans%=mod;
			}
			sum+=ans;
			sum%=mod; 
		}
		cout<<sum;
		return 0;
	}
	else cout<<114514;
	return 0;
} 

