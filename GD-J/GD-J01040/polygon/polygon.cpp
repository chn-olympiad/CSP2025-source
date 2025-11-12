#include<bits/stdc++.h>
using namespace std;
long long n,sum=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) sum=sum*2%998244353;
	sum-=n*n/2;
	sum-=n;
	if(sum<0) sum+=998244353;
	cout<<sum;
}
