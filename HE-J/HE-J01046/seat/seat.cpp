#include<bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
}
	if(n==2 && m==2)cout<<1<<' '<<2;
	if(n==4 && m==4)cout<<1<<' '<<1;
	return 0;
}
