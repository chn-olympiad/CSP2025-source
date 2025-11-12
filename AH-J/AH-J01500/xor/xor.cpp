#include <bits/stdc++.h>
using namespace std;
long long a,b,c[555555],m,p,q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++) cin>>c[i];
	for(int i=1;i<=a;i++) if(c[i]==1) m++;
	if(m%2==0){if(b==1) cout<<m-1;else cout<<m;}
	else{if(b==1) cout<<m;else cout<<m-1;}
	return 0;
}
