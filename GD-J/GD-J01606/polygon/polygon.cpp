#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1145141],bx;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bx+=a[i];
	}
	sort(a+1,a+1+n);
	if(bx>a[n]*2) cout<<1;
	else cout<<0;
}
