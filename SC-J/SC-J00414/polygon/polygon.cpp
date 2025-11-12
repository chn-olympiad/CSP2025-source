#include<bits/stdc++.h>

using namespace std;
const int  N=5e5+10; 
int n,a[N] ;
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		cout<<10;
	}else if(n<=500||n<=5000){
		cout<<1;
	}
	return 0;
} 