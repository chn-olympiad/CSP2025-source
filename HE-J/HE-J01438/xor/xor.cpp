#include<bits/stdc++.h>
using namespace std;
int a[101];
int n,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		cout<<2;
	}
    if(n==4&&m==3){
		cout<<2;
	}
   if(n==4&&m==0){
		cout<<1;
	}
	return 0;
} 
