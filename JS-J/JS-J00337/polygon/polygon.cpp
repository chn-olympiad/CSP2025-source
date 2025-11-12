#include <iostream>
using namespace std;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3){
		int x=a[1]+a[2]+a[3];
		int max1=0;
		max1=max(a[1],max(a[2],a[3]));
		if(x>max1*2)
		{
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	long long sum=0;
	for(int i=3;i<=(n%2?n/2+1:n/2);i++)
	{
		long long x=1,y=1;
		for(int j=n;j>=n-i+1;j++)
		{
			x*=j;
			x%=998244353;
		}
		for(int j=1;j<=i;j++)
		{
			y*=j;
			y%=998244353;
		}
		sum+=(x/y)%998244353;
	}
	sum%=998244353;
	sum*=2;
	sum%=998244353;
	cout<<sum;
	return 0;
}
