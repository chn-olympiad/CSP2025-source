#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5007];
long long jie[5000];
long long nijie[5000];
long long super_pow(long long a){
	int p=mod-2;
	long long bian=a;
	long long final=1;
	for(int i=0;(1<<i)<=p;i++){
		if((1<<i)&p){
			final=(bian*final)%mod;
		}
		bian=(bian*bian)%mod;
	}
	return final;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	jie[1]=1;
    for(int i=2;i<=4997;i++){
    	jie[i]=i*jie[i-1]%mod;
	}
	//////check!!!!!!!!!
	nijie[4997]=super_pow(jie[4997]);
	for(int i=4996;i>=1;i--){
    	nijie[i]=(nijie[i+1]*(i+1))%mod;
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int z=j+1;z<=n;z++){
				if(a[i]+a[j]+a[z]>2*a[z]){
					cnt=(cnt+1)%mod;
					for(int k=1;k<i;k++){
						int m=i-1;
						if(m==k){
							cnt=(cnt+1)%mod;
							continue;
						}
						cnt=(cnt+(jie[m]*nijie[k]*nijie[m-k])%mod)%mod;
					}
				}
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
} 
