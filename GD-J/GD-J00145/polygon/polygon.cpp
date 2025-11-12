//Forza Ferrari!
//baolichuqiji
#include<iostream>
using namespace std;
long long a[5005];
long long n;
long long ferrari=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		// if(n-i<3)break;
		long long ans=0;
		long long max1=-114514;
		for(int j=i;j<=n;j++){
			ans+=a[j];
			max1=max(max1,a[j]);
		}
		if(ans>2*max1)ferrari++;
	}
	cout<<ferrari%998244353;
}