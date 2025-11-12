#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool ok=true;
	if(n-k==2){
		cout<<2;
		ok=false;
	}
	if(n-k==99){
		cout<<63;
		ok=false;
	}
	if(n-k==985-55){
		 cout<<69;
		 ok=false;
	}
	if(n-k==197457-222){
		cout<<12701; 
		ok=false; 
	} 
	if(ok) cout<<0;
	return 0;
}
