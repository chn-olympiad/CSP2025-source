#include<bits/stdc++.h>
#define ll long long 
using namespace std;

long long s[5000],c[5000],n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int q=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!=1)q=0;
	}
	for(int j=1;j<=m;j++){
		cin>>c[j];
	}
	ll mod=998244353;
	if(q==1){
		ll sumn=1,summ=1,sumnm=1;
		for(int i=1;i<=n;i++){
			sumn*=i%mod;
		}
		for(int i=1;i<=m;i++){
			summ*=i%mod;
		}
		for(int i=1;i<=n-m;i++){
			sumnm*=i%mod;
		}
		cout<<(sumn%mod)/((summ%mod)*(sumnm%mod));
		return 0;
	//	998, 244, 353
	}
	else if(m==1){
		cout<<n;
		return 0;
	}
	
	
	return 0;
}
