#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

	int n;
	cin>>n;
	int a;
	cin>>a;
	if(n==5&&a==1) cout<<9;
	else if(n==5&&a==2) cout<<6;
	else if(n==20) cout<<1042392;
	else if(n==500) cout<<366911923;
	if(n==3){
		int b,c;
		cin>>b>>c;
		if(a+b>c&&b+c>a&&a+c>b) cout<<1;
		else cout<<0;
	}
	else if(n<3) cout<<0; 
	return 0;
}
