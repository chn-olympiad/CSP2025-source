#include<bits/stdc++.h>
using namespace std;
long long n,x;
long long sum[5005],a[5005],b[5005];
long long jc(long long x){
	if(x==1) return 1;
	if(b[x]!=0) return b[x];
	return b[x]=jc(x-1)*x;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a[0];
	sum[0]=a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=jc(n)/(jc(i)+jc(n-i));
	}
	cout<<ans;
	return 0;
}
