#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353; 
long long n,m,c[505],zs=0,f[18][300005],bs=0,rm[20],bo[22],df=0,op=0,as=1,sw=0;
char s[505]; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='1'){
			zs++;
		} 
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			sw++;
		}
	}
	rm[0]=1;
	for(int i=1;i<=18;i++){
		rm[i]=rm[i-1]*2ll%mod; 
	} 
	if(n<=18){
		bs=pow(2,n)-1;
		f[0][0]=1;
		for(int i=0;i<=n-1;i++){
			for(int j=0,k;j<=bs;j++){
				k=j;
				df=0; 
				for(int o=0;o<=n-1;o++){
					if(k%2==1){
						bo[o]=1; 
						df++; 
					} 
					else{
						bo[o]=0; 
					} 
					k/=2;
				} 
				for(int o=0;o<=n-1;o++){
					if(bo[o]==0){
						if(s[df+1]=='0'){
							f[i][j+rm[o]]=(f[i][j+rm[o]]+f[i][j])%mod; 
						} 
						else{
							if(c[o+1]<=df-i){
								f[i][j+rm[o]]=(f[i][j+rm[o]]+f[i][j])%mod;
							}
							else{
								f[i+1][j+rm[o]]=(f[i+1][j+rm[o]]+f[i][j])%mod;
							}
						}
					} 
				} 				
			} 
		} 
		op=0;
		for(int i=m;i<=n;i++){
			op=(op+f[i][bs])%mod;
		}
		cout<<op<<endl;
	}
	else{
		cout<<0<<endl;
	}
	return 0;
}
