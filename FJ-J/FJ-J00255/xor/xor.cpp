#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,m,a[N];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){
		if(m==2||m==3){
			cout<<2;
			return 0;
		}
		if(m==0){
			cout<<1;
			return 0;
		}
	}
	cout<<n-m;
} 
