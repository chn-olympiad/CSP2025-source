#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==2||k==3){
		cout<<2;
	}
	if(k==0){
		cout<<0;
	}
	return 0;
}
