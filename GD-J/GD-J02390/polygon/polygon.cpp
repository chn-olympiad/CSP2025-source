#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],fas=0,m;
int mod(long long nn){
	return nn%998244353;
}
int qh(int l,int r){
	int he=0; 
	for(int i=l;i<=r;i++){
		he+=a[i];
	}
	return he;
}
bool ok(int q,int l,int r){
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-3;i++){
		for(int j=i+3;j<=n;j++){
			if(a[j]*2>qh(i,j)) fas++;
		}
	}
	cout<<mod(fas);
	return 0;
}

