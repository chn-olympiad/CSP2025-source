#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a>>b>>c;
	int x=max(max(a,b),c);
    if(a+b+c>(2*x)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
