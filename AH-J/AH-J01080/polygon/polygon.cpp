#include<bits/stdc++.h>
using namespace std;
int a[10009];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2) cout<<0;
	if(n==3){
		int k=a[1],j=a[2],k2=a[3];
		if(k+j>k2&&k+k2>j&&j+k2>j) cout<<1;
		else cout<<0;
	}
	return 0;
}
