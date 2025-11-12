#include <bits/stdc++.h>
using namespace std;
int a,b,c,n; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a>>b>>c;
	if((a+b+c)>(2*max(a,max(b,c)))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
