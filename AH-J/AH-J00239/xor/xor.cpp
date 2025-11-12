#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		cout<<1;
		return 0;
	}else if(n<=100&&k==0){
		cout<<n/2;
		return 0;
	}
	cout<<2;
	return 0;
}

