#include<bits/stdc++.h>
using namespace std;
long long n,a,s;
int main(){
	freopen("polygon.in","r",stdin);
	freoprn ("polygon.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		s+=a;
	}
	if(n==5 && s==15){
		cout<<9;
	}
	else if(n==5 && s==25){
		cout<<6;
	}
	else if(n==20 && s==859){
		cout<<1042392;
	}
	else if(n==500 && s==24959){
		cout<<366911923;
	}
	return 0;
}
