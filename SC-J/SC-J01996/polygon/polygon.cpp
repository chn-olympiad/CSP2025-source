#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[10],x=0,l=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=max(a[i],x);
		l+=a[i];
	}
	if(n<=2){
		cout<<0;
	}
	else if(l<x*2){
		cout<<0;
	}
	else cout<<1;
	
	return 0;
}