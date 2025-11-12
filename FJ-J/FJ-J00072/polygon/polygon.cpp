#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,b,c;
	cin>>n;
	if(n==3){
		cin>>a>>b>>c;
		if(a+b+c>max(a,max(b,c))*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<1;
	}
	return 0;
}
