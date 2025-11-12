#include<bits/stdc++.h>
using namespace std;
int a,b,c,n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a>>b>>c;
	int maxnum=max(max(a,b),c);
	if(a+b+c > 2*maxnum)cout<<1;
	else cout<<0;
	return 0;
}
