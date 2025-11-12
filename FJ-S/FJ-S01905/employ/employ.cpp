#include<bits/stdc++.h>
using namespace std;
long long n,m,r[510],t0=0;
string sf;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>sf;
	
	sf="2"+sf;
	for(long long i=1;i<=n;i++){
		cin>>r[i];
		if(!r[i]) t0++;
	}
	sort(r+1,r+1+n);
	if(sf.find('1')==-1){
		cout<<0;//cout<<"*";
		exit(0);
	}
	if(m==n){//cout<<"/";
		if(sf.find('0')!=-1 or t0!=0){
			cout<<0;
		}
		else{
			long long ans=1;
			for(long long i=2;i<=n;i++){
				ans=ans*(i%mod);
				ans=ans%mod;
			}
			cout<<ans;
		}
		exit(0);
	}
	if(m==1){//cout<<"+";
		long long x=sf.find('1'),jl=n+1;
		for(long long i=1;i<=n;i++){
			if(r[i]>=x){
				jl=i;break;
			}
		}
		jl=n+1-jl;
		jl=jl%mod;
		for(long long i=2;i<n;i++){
			jl=(jl*(i%mod))%mod;
		}
		cout<<jl;
		exit(0);
	}
	if(n-t0>=m){//cout<<"-";
		long long jl=1;
		for(long long i=2;i<=n;i++){
			jl=(jl*(i%mod))%mod;
			cout<<jl<<"\n";
		}
		cout<<jl;
	}else cout<<"0";
	return 0;
}
