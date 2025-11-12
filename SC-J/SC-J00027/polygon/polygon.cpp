#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
	cin>>n;
	cin>>a>>b>>c;
	int mx=max(a,max(b,c));
	if((a+b+c)>(2*mx))cout<<1;
	else cout<<0;
	return 0;
}