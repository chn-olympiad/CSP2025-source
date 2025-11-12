#include<bits/stdc++.h>
using namespace std;
int nu,ma,a[10],n,m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>ma)ma=a[i];
		nu+=a[i];
	}
	if(nu>ma*2)cout<<1;
	return 0;
}
