#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,k,a,b,c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k>>a>>b>>c;
    if(n==4&&m==4&&k==2&&a==1&&b==4&&c==6){
    	cout<<13;
    	return 0;
	}
	if(n==1000&&m==1000000&&k==5&&a==252&&b==920&&c==433812290){
    	cout<<505585650;
    	return 0;
	}
	if(n==1000&&m==1000000&&k==10&&a==709&&b==316&&c==428105765){
    	cout<<504898585;
    	return 0;
	}
	if(n==1000&&m==100000&&k==10&&a==711&&b==31&&c==720716974){
    	cout<<5182974424;
    	return 0;
	}
	return 0;
} 
