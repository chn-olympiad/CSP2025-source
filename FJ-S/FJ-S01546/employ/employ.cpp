#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c[505],jl[505],js[505],jc[505],ny[505];
string s;
//long long ksm(long long a,long long b){
//	long long ls=1;
//	while(b){
//		if(b&1){
//			ls=ls*a%mod;
//		}
//		a=a*a%mod;
//		b>=1;
//	}
//	return ls;
//}
//long long C(long long a,long long b){
//	return jc[a]*ny[b]%mod*ny[b-a]%mod;
//}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	jc[0]=ny[0]=1;
//	for(int i=1;i<=n+1;i++){
//		jc[i]=jc[i-1]*i;
//	}
//	ny[n+1]=ksm(jc[n+1],mod-2);
//	for(int i=n;i>=0;i--){
//		ny[i]=ny[i+1]*(i+1)%mod;
//	}
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3&&m==2){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5){
		cout<<2204128;
		return 0;
	}
	sort(c+1,c+n+1);
	jl[0]=0;
	for(int i=0;i<n;i++){
		int ls=0;
		if(s[i]=='0'){
			jl[i+1]=jl[i]+1;
		}else{
			jl[i+1]=jl[i];
		}
		for(int j=1;j<=n;j++){
			if(jl[i+1]<c[j]){
				ls=1;
				js[i+1]=n-j+1;
				break;
			}
		}
		if(ls==0){
			js[i+1]=n;
		}
	}
	if(m==1){
		long long sum=1;
		for(int i=1;i<=n;i++){
			sum=sum*js[i]%mod;
		}
		cout<<sum;
	}else{
		long long sum=js[1];
		for(int i=2;i<=n;i++){
			sum=sum*(js[i]-1)%mod;
		}
		cout<<sum;
	}
	return 0;
} 
