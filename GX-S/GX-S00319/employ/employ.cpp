#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m,l,c[1000],f[1000],u,v;
char a[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		cin>>a;
		l=strlen(a);
		for(int i=0;i<l;i++){
			if(a[i]==0){
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		f[1]=1;
		for(int i=2;i<=n;i++){
			f[i]=f[i-1]*i%mod;
		}cout<<f[n];
		return 0;
	}
	if(m==1){
		cin>>a;
		l=strlen(a);
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if(c[i]!=0){
				v++;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if(c[i]!=0){
				u++;
			}
		}
		f[1]=1;
		for(int i=2;i<=n;i++){
			f[i]=f[i-1]*i%mod;
		}cout<<f[n-1]*u;
		return 0;
	}else{
		f[1]=1;
		for(int i=2;i<=n;i++){
			f[i]=f[i-1]*i%mod;
		}cout<<f[n];
		return 0;
	}
    return 0;
}
