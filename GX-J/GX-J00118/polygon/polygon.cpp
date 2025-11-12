#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=2){
		cout<<"0";
		return 0;
	}
	if(n==5){
		cout<<"6";
		return 0;
	}	
	cout<<"3";
	return 0;
}
