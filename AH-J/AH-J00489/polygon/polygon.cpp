#include<bits/stdc++.h>
using namespace std;
int a[10003];
long long mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >>n;
	int sum1=0;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
		if(a[i]==1) sum1++;
	}
	if(sum1==n)
	{
		long long ans=1,sum=0;
		for(int i=3;i<=n;i++)
		{
			ans=1;
			for(int j=1;j<=i;j++)
				ans=(ans*(n-j+1)/j)%mod;
			sum=(sum+ans)%mod;
		}
		cout <<sum;
	}
	else if(n<3) cout <<0;
	else if(n==3)
	{
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]) cout <<1;
		else cout <<0;
	}
	else return 0;
	return 0;
}
