#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","a",stdout);
	int a,b,c,d;
	cin>>d>>a>>b>>c;
	d=max(a,max(b,c));
	if(2*d>a+b+c){
		cout<<1;
	}else{
		cout<<0;
	}

	return 0;
} 
//I love China.I'm from China.
