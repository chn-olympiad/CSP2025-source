#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b>>c;
	if(abs(a-b)<c&&abs(a-c)<b&&abs(b-c)<a){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
