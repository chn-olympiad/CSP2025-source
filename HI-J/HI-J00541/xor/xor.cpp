#include<bits/stdc++.h>
using namespace std;
int z[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>z[i];
	}
	if(n==2){
		if(z[1]==z[2]){
			cout<<'1'; 
		}else if(z[1]==0){
			cout<<'1'; 
		}else if(z[2]==0){
			cout<<'1'; 
		}else{
			cout<<'0';
		}
	}else if(n==1){
		if(z[1]==0){
			cout<<'1'; 
		}else{
			cout<<'0';
		}
	}
	return 0;
}

