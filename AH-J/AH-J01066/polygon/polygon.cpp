#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b+c>2*(max(max (a,b),c)))cout<<1;
	else cout<<0;
	return 0;
}
