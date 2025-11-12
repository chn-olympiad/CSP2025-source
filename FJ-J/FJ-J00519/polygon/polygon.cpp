#include<bits/stdc++.h>
using namespace std;
int n,a;
int num=0,maxx=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		num+=a; 
		maxx=max(a,maxx);
	} 
	if(a>maxx*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
