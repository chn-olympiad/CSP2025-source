#include<bits/stdc++.h>
using namespace std;
int x,y,z,maxx=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","W",stdout);
	int n;
	cin>>n;
	cin>>x>>y>>z;
	maxx=max(x,y);
	maxx=max(maxx,z);
	if(x+y+z>maxx*2) cout<<1;
	else cout<<0;
	return 0;
}
