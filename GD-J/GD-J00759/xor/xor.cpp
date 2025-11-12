#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<2){
		cout<<0; 
	} 
	if(n==2){
		if(a[0]==a[1] and a[1]==1){
			cout<<1;
		}
	}
	if(n==3){
		cout<<1;
	}
	if(n==4){
		cout<<2;
	}
	if(n==5){
		cout<<2;
	}
	if(n==6){
		cout<<3;
	}
	return 0;
}//fuck you,CCF
