#include<bits/stdc++.h>
using namespace std;
long long a,b,c,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a>>b>>c;
	int ma=max(a,max(b,c));
	if(a+b+c>2*ma) cout<<1;
	else cout<<0;
	return 0;
}
