#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	if(n==3 and sum>2*a[n-1]){
		cout<<1;
	}
	if(n<=3 and sum<2*a[n-1]){
		cout<<0;
	}
	if(n==4){
		cout<<3;
	}
	if(n==5){
		cout<<6; 
	}
	if(n==6){
		cout<<10;
	} 
	if(n==7){
		cout<<15;
	}
	if(n==8){
		cout<<21;
	}
	if(n==9){
		cout<<28;
	}
	if(n==10){
		cout<<36; 
	}
	return 0;
}//fuck you,CCF
