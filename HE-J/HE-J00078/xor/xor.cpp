#include <bits/stdc++.h>;
using namespace std;
int a[500005];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<1;
	}
	
	return 0;
}
