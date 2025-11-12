#include<bits/stdc++.h>
using namespace std;
int n,m,r,a[315],w=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>r)w++;
	}
	int y=w/n,x=w%n;
	if(w%n!=0)y++;
	if(y%2==0&&x==0)x=1;
	if(y%2==0)x=n+1-x;
	if(y%2!=0&&x==0)x=n;
	printf("%d %d",y,x);
	return 0;
} 
