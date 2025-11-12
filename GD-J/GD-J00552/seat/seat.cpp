#include<bits/stdc++.h>
using namespace std;
int n,m,a[205],k,t,l,c,xx,yy,z;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>k;
	t=n*m-1;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+t,cmp);
	l=n*m;
	for(int i=1;i<=t;i++){
		if(k>a[i]){
			l=i;
			break;
		}
	}
	if(l%n==0)c=l/n;
	else c=l/n+1;
	xx=c;
	z=l-l/n*n;
	if(z==0)z=n;
	if(c%2==0){
		yy=n-(c*n-l+1)+1;
	}
	else{
		yy=z;
	}
	cout<<xx<<" "<<yy;
	return 0;
}

