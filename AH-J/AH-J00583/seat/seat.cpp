#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[200],x=1,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) x++;
	}
	c=x/n;
	r=x%n;
	if(r==0)
		cout<<c<<' '<<n;
	else
		if(c%2==0) cout<<c+1<<' '<<r;
		else cout<<c+1<<' '<<n+1-r;
	return 0;
}
