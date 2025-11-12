#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,b,c,d,z;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>b>>c>>d;
		z=max(b,max(c,d));
		if(b+c+d>2*z)cout<<1;
		else cout<<0;
	}
	return 0;
}
