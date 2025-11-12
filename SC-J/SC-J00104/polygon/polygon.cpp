#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b+c>max(max(a,b),c)*2){
			if(a+b>c&&a+c>b&&b+c>a&&abs(a-b)<c&&abs(a-c)<b&&abs(b-c)<a) {
				cout<<1;
			}
		}
	}
	else{
		cout<<0;
	}
	return 0;
}