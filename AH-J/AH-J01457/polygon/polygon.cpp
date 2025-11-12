#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,a,b,c;
	cin>>n;
	cin>>a>>b>>c;
	if(a+b+c>max(max(a,c),b)*2)cout<<"1";
	else cout<<'0';
	return 0;
}

