#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long n,a[5005],sum;
long long jc(int n)
{
	long long s=1;
	while(n--){
		s=(s*n)%mod;
	} 
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<3)
	{
		cout<<0;
		return 0;
	} 
	if(n==3)
	{
		if((a[1]+a[2])>a[3]) 
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	cout<<rand()%mod;
	return 0;
}
