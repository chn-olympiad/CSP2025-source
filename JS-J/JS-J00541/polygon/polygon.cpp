#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long modd=998244353;
long long ans;
long long jiec(long long x){
	long long sum=1;
	for(long long i=1;i<=x;i++){
		sum=sum*i;
	}
	return ans;
}
long long c(long long x,long long y){
	long long sum;
	sum=(jiec(y)/(jiec(y-x)*jiec(x)))%modd;
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]) cout<<"1";
		else cout<<"0";
	}
	else if(n<3) cout<<"0";
	else{
		for(int i=1;i<=n;i++){
			ans+=c(i,n);
		}
		cout<<ans;
	}
	return 0;
}
