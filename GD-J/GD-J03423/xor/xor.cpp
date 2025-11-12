#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],t,y;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		if(a[i]==m){
			t++;
		}
	}
	cout<<t;
	return 0;
} 
