#include<bits/stdc++.h>
using namespace std;
long long in,r,n,a,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a>>b>>c;
	if(max(a,max(b,c))*2<a+b+c){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

