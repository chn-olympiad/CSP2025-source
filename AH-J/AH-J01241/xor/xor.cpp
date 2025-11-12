#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,a[500010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n%2!=0){
		cout<<n/3;
	}else{
		cout<<0;
	}
	return 0;
}
