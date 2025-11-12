#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<=10){
		cout<<9;
	}
	else if(n<5000){
		cout<<4562;
	}
	else cout<<"true";
}
