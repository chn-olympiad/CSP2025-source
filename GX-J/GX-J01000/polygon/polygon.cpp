#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,b,c,m;
	cin>>n;
	if(n==1){
		cin>>a;
		cout<<0;
	}
	if(n==2){ 
		cin>>a>>b;
		cout<<0;
	}
	if(n==3){
		cin>>a>>b>>c;
		m=max(a,max(b,c));
		if((a+b+c)>2*m)cout<<1;
		else cout<<0;
	}
	return 0;
}
