#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000],s,b[100000];
int egg(int k,int l,int sum,int d){
	if(k>l){
		if(2*b[l]<sum) s++;
		s%=998244353;
		return 0;
	}
	for(int i=d;i<=n;i++){
		if(k==l&&sum<a[i]) continue;
		b[k]=a[i];
		egg(k+1,l,sum+a[i],i+1);
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		egg(1,i,0,1);
	}
	cout<<s;
	return 0;
}

