#include<bits/stdc++.h>
using namespace std;
int a[111];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=1;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]) x++;
	}
	int c,r,w;
	if(x%n==0) c=x/n,w=n;
	else c=x/n+1,w=x%n;
	if(c%2==1) r=w;
	else r=n-w+1;
	cout<<c<<" "<<r;
	return 0;
}
