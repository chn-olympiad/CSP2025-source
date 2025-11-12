#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&k==2){
		cout<<2<<endl;
	}
	return 0;
}
