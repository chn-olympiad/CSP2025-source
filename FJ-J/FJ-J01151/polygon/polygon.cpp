#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cdh=0,zdz=0;
int a[5010]; 
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cdh+=a[i];
		zdz=max(zdz,a[i]);
	}
	if(n<=3){
		if(zdz*2<cdh){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
} 
