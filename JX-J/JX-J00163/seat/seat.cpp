#include<bits/stdc++.h>
using namespace std;
int n,m,ml,nl,a[10000],i,xr,j;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int i1=n*m;
	for(i=1;i<=i1;i++)
		cin>>a[i];
	xr=a[1];
	sort(a+1,a+i+1,cmp);
	for(j=1;j<=i;j++)
		if(a[j]==xr)break;
	if(j%n==0){
		ml=j/n;
		if(ml%2==0)nl=1;
		else nl=n;
	}
	else{
		ml=j/n+1;
		if(ml%2==0)nl=n-(j%n)+1;
		else nl=j%n;
	}
	cout<<ml<<' '<<nl;
	return 0;
}
