#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],l,q,o;
long long k;
char a[505];
int main(){ 
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	l=n;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		q=max(q,c[i]);
		if(c[i]==0)
			--l;
	}
	k=1,o=1;
	if(m==1){
		for(int i=2;i<q;++i){
			k*=i;
			k=k%998244353; 
		}for(int i=2;i<=n-q;++i){
			o*=i;
			o=o%998244353; 
		}
		k*=o;
		k=k%998244353; 
	}else{
		for(int i=2;i<=l;++i){
			k*=i;
			k=k%998244353; 
		}
	}
	cout<<k;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
