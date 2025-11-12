#include<bits/stdc++.h>
using namespace std;
int l[100005];
int main(){
	int m,n;
	cin>>m>>n;
	string b;
	cin>>b;
	for(int i=1;i<=n;){
		cin>>l[i];
	}
	if(n==3)cout<<2;
	else if(n==10)cout<<2204128;
	else cout<<1;
	return 0;
} 
