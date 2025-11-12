#include<bits/stdc++.h>
using namespace std;


int n,a[5002],res,k[11];

int main(){
	cin>>n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	if(n<=3){
		int a,b,c;
		cin>>a>>b>>c;
		if(max(a,b,c) >= 2*(a+b+c))
			cout<<1;
		else
			cout<<0;
	}
	return 0;
}
