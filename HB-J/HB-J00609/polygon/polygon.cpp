#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<0;
		return 0;
	}
	else{
		cin>>a>>b>>c;
	}
	if(max(a,max(b,c))>(a+b+c)/2){
		cout<<1;
		return 0;
	}
	return 0;
}
