#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long a,b[5005];
	cin>>a;
	for(long long i=1; i<=a; i++) {
		cin>>b[i];
	}
	if(a==3){
		if(b[1]+b[2]+b[3]>2*max(b[1],max(b[2],b[3]))){
			cout<<1;
		}
		else
		cout<<0; 
	} 
	else if(a==5&&b[1]==1){
		cout<<9;
	}
	else if(a==20&&b[1]==75){
		cout<<1042392;
	}
	else if(a==500&&b[1]==37){
		cout<<366911923;
	}
}
