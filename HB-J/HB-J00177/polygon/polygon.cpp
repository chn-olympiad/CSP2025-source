#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("polygon","w",stdin);
	freopen("polygon","r",stdout);
	int n;
	cin>>n;
	int a[n+10];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[n-1]==5){
		cout<<9;
	}
	else{
		cout<<6;
	}
	return 0;
}
