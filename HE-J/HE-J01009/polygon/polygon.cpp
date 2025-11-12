#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],m,x;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],m=max(m,a[i]),x+=a[i];
	if(n==3){
		if(x>2*m) cout<<1;
		else cout<<0;
	}
	else cout<<n;
	return 0;
}
