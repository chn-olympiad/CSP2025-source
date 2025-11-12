#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a>>b>>c;
	if(a+b<c){
		return 0;
	}
	if(a+c<b){
		return 0;
	}
	if(b+c<a){
		return 0;
	}
	cout<<1;
	return 0;
}
