#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[105],stp=1,ansx,ansy;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int x=a[1];
	for(int i=2;i<=n*m;i++){
		if(a[i]>x) stp++;
	}
	ansx=(stp-1)/n+1;
	if(stp%(2*n)<=n){
		ansy=stp%n;
		if(!ansy) ansy=n;
	}
	else
	{
		ansy=n-(stp%n)+1;
		if(stp%n==0) ansy=1;
	}
	printf("%d %d",ansx,ansy);
}
