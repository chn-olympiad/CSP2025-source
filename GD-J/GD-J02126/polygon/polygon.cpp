#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sum,ans,maxn=998244353;
long long f(int i){
	if(i==n) return 0;
	long long as=f(i+1)%maxn;
	sum+=a[i];
	if(a[i]*2<sum) as=(as+1)%maxn;
	as=(as+f(i+1)%maxn)%maxn;
	sum-=a[i];
	return as;
}
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	ans=f(0);
	cout<<ans;
	return 0;
}
