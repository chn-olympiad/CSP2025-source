#include<bits/stdc++.h>
using namespace std;
int a[500000];int n,k,ans=0;bool f[500000]={0};
int nm(int p){
	int u=1;
	if(p==0)return u;
	else for(int i=1;i<=p;i++)u*=2;
	return u;
}
int xo(int n,int m){
	int a1[10]={0},a2[10]={0},a3[10]={0},a4[10]={0};
	int p=0;
	while(n!=0){
		a3[p++]=n%2;
		n/=2;
	}
	int qq=0;
	for(int i=p-1;i>=(p-1)/2+1;i--)swap(a3[i],a3[p-1-i]);
	for(int i=8-p;i<8;i++){
	a1[i]=a3[qq++]; }
	
	p=0;
	while(m!=0){
		a3[p++]=m%2;
		m/=2;
	}
	qq=0;
	for(int i=p-1;i>=(p-1)/2+1;i--)swap(a3[i],a3[p-1-i]);
	for(int i=8-p;i<8;i++){
	a2[i]=a3[qq++]; }
	
	for(int i=0;i<8;i++){
		if(a1[i]==1 && a2[i]==1)a4[i]=0;
		else a4[i]=a1[i]+a2[i];
	}
	int o=0;int y=1;
	for(int i=7;i>=0;i--){
		o+=a4[i]*nm(7-i);
	}
	return o;
}
int r(int m){
	if(m>=n) return 0;
	for(int i=0;i<n;i++){
		if(xo(a[i],a[m])==k &&m!=i&& !f[m] && !f[i]){
			ans++;
			f[m]=1;
			f[i]=1;
		}
		else r(m+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(xo(a[i],0)==k){ans++;
		f[i]=1;
		}
	}
	r(0);
	cout<<ans;
	return 0;
}
