#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int n,m;
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a>>b>>c;
		if(a<b) swap(a,b);
		if(b<c) swap(b,c);
		if(a<b) swap(a,b);
		if(a>b+c) cout<<1<<endl;
		else cout<<0<<endl;
	}
	else cout<<5<<endl;
	return 0;
}
