#include <bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a>>b>>c;
	cout<<int(a+b+c>2*max({a,b,c}));
	return 0;
}
