#include<bits/stdc++.h>
using namespace std;
int s[550000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int m,l=0,n=0;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>s[i];
		l=max(l,s[i]);
		n+=s[i];
	}
	if(n>2*l){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
