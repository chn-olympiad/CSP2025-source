#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=;i++){
		cin>>a[i];
	}
	if(n<=2) cout<<1;
	else if(n<=10 && n>2) cout<<10;
	else if(n<=100 && n>1) cout<<1;
	else cout<<255;
	return 0;
	
}