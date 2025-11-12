#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a>>b>>c;
	if(a<b+c&&b<a+c&&c<a+b&&c>a-b&&c>b-a&&a>b-c&&a>c-b&&b>a-c&&b>c-a){
		cout<<1; 
	}else{
		cout<<0;
	}
}
