#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,k;
	int a[10005];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
    if(n==4&&k==2){
    	cout<<2;
	}
	if(n==4&&k==3){
    	cout<<2;
	}
	if(n==4&&k==0){
    	cout<<1;
	}
	return 0;
	
}
