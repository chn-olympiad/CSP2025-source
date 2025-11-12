#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		cout<<1;
	}
	 if(n%m==0){
		cout<<m;
	}else{
		cout<<m-1;
	} 
	
	
	return 0;
} 
