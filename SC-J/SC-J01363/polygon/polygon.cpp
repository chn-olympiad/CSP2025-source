#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,b,c;cin>>n>>a>>b>>c;
	if(n>3)return cout<<n,0;
	if(a+b>c&&a+c>b&&b+c>a)return cout<<1,0;
	return cout<<0,0;
}