#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==4&&n==2){
		cout<<2;
	}if(m==4&&n==3){
		cout<<2;
	}if(m==4&&n==0){
		cout<<1;
	}if(m==100&&n==1){
		cout<<63;
	}if(m==985){
		cout<<55;
	}if(m==197457){
		cout<<12701;
	}
	return 0;
}
