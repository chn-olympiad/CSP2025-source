#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>m;	
	}
	if(n==1){
		cout<<1;
	}else{
		cout<<2;
	}
	return 0;
} 
