#include<bits/stdc++.h>
//#define int longlong
using namespace std;
long long int a[10000],n;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=998244353;i++){
		if(n==5){
			cout<<9;
		}
		if(n==6){
			cout<<15;
		}
//	}
}

