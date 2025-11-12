#include<iostream>
#include<cstdio>
using namespace std;
const int N=5e3+50;
const unsigned long long MOD=998244353;
int a[N];
unsigned long long d[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3) {
		if(n==3) {
			if((a[1]+a[2]+a[3])>2*(max(max(a[1],a[2]),a[3]))){
				cout<<1;
			}else {
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else {
		unsigned long long ans=0;
		d[0]=1;
		for(unsigned long long i=1;i<=(unsigned long long)(n);i++) {
			d[i]=d[i-1]*i;
		}
		for(unsigned long long i=3;i<=(unsigned long long)(n);i++) {
			ans=(ans+(d[n]/d[n-i]/d[i]))%MOD;
		}
		cout<<ans;
	}	
	return 0;
}