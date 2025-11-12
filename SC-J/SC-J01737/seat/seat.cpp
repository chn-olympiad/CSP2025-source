#include<bits/stdc++.h>
using namespace std;

int n,m,t,c,x,y;
int a[200];

bool cmp( int l,int r ){
	return l>r;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for( int i=1; i<=n*m; ++i ){
		cin>>a[i];
	}
	t=a[1];
	sort( a+1,a+n*m+1,cmp );
	for( int i=1; i<=n*m; ++i ){
		if( a[i]==t ){
			c=i;
			break;
		}
	}
	y=ceil(1.0*c/n);
	if( y%2 ) x=c+n-y*n;
	else x=y*n-c+1;
	cout<<y<<" "<<x;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}