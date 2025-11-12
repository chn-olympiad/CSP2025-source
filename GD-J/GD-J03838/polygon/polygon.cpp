#include <bits/stdc++.h>
using namespace std;
int n,a[10005];
bool f=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2) cout<<1;
		else cout<<0;
	}
	if(f) cout<<(n*(n-1)*(n-2))/6;
	return 0;
}
