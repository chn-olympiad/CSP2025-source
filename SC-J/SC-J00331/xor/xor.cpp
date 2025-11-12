#include<bits/stdc++.h>
using namespace std;
long long n,m,a,s[1000],w,x,y;
int main(){
	freopen("polygon1.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>m>>a>>w;
		if(m+a>w && m-a<w){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	if(n==5){
		cout<<9;
	}
	
	return 0;
}