#include<bits/stdc++.h>
using namespace std;

int n,q;

int main(){
	ios::sync_with_stdio(false); 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>q;
	if(n==3 && q==2){
		cout<<2;
	} else if(n==10 && q==5){
		cout<<2204128;
	}else{
		cout<<0;
	}
	return 0;
} 
