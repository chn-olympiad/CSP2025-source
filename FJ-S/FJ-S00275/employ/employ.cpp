#include <bits/stdc++.h>
using namespace std;
int a,b,c;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	cin>>s;
	c=1;
	while(a--){
		c*=a+1;
		c=c%998244353;
	}
	cout<<c;
	return 0;
}