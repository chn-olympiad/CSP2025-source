#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b,c,n;
	cin>>n>>a>>b>>c;
	int d=max(max(a,b),c);
	if(d==a){
		if(b+c>a){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(d==b){
		if(a+c>b){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(d==c){
		if(b+a>c){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
