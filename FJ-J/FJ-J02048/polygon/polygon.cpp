#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],b[5005],f[25000052],s,x;
void g(long long y){
	for(long long i=b[y-1];i>=a[y]+1;i--){
		x=(x+f[i])%mod;
		f[i+a[y]]=(f[i+a[y]]+f[i])%mod;
	}
	for(long long i=1;i<=a[y];i++){
		if(f[i]){
			f[i+a[y]]+=f[i];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		b[i]=b[i-1]+a[i]; 
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<n;i++){
		for(long long j=1;j<i;j++){
			f[a[i]+a[j]]+=1; 
		}
		g(i+1);
	}
	cout<<x;
	return 0;
}
