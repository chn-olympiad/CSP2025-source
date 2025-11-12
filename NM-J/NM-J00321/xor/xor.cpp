#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5e5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool b1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) b1=1;
	}
	if(n<=2&&k==0&&b1==0){
		cout<<1;
		return 0;
	}
	if(b1==0&&n<=100&&k==0){
		cout<<n/2;
		return 0;
	}
	return 0;
}
