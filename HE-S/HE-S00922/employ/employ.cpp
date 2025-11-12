#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
long long n,m,f[1005],ny[1005];
long long qpow(long long a,long long b){
	long long res=a;
	while(b){
		if(b&1){
			res*=a;
			res%=P;	
		}
		res*=res;
		res%=P;
		b>>=1;
	}
	return res%P;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	f[1]=ny[1]=1;
	for(int i=2;i<=1000;i++) f[i]=i*f[i-1];
	for(int i=2;i<=1000;i++) ny[i]=qpow(f[i],P-2);
	cout<<f[n-m]*ny[m]%P;
} 
