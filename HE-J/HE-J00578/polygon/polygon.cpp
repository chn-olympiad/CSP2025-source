#include <bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,b,c;
	cin>>n;
	if(n<3) cout<<0;
	if(n==3) cin>>a>>b>>c,cout<<(a+b+c>2*max(a,max(b,c)));
	cout<<n;
	return 0;
} 
