#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
char f[N];
int a[N];
int c[N];
bool f1=true;
long long ans=1;
void check(){
	int k=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0) k+=1;
	}
	for(int i=1;i<=m;i++){
		ans=(ans*(n-k-i+1)%mod+mod)%mod;
	}
	for(int i=1;i<=n-m;i++){
		ans=(ans*(n-m-i+1)%mod+mod)%mod;
	}
	return;
}
void check2(){
	int k=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0) k+=1;
	}
	for(int i=1;i<=m;i++){
		ans=(ans*(n-k-i+1)%mod+mod)%mod;
	}
	for(int i=1;i<=n-m;i++){
		ans=(ans*(n-m-i+1)%mod+mod)%mod;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		a[i]=f[i]-'0';
		if(a[i]==0) f1=false;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(f1==true) {
		check();
		cout<<ans<<endl;
		return 0;
	}
	check2();
	cout<<ans<<endl;
	return 0;
} 
