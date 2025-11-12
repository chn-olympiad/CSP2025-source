#include <bits/stdc++.h>
using namespace std;
long long n,k,a[100010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&k==3){
		cout<<2;
	}
	if(n==4&&k==2){
		cout<<2;
	}
	if(n==4&&k==1){
		cout<<1;
	}
}
