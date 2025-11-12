#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],qzh[5000],mj[5000];
long long ans=0;
long long dcsl(int x) {
	long long sum=0;
	for(int i=x; i>=3; i--) {
		sum+=qzh[x-i+1];
	}
	return sum;
}
void ycl() {
	for(int i=1; i<=n; i++) {
		qzh[i]=qzh[i-1]+i;
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	ycl();
	cout<<dcsl(n)%mod;
	return 0;
}
//特殊性质这一块 
