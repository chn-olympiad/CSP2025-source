#include<bits/stdc++.h>
using namespace std;

int n,m,k,p=1,x,y,b;
int a[1007];
bool cmp(int a1,int a2){
	return a1>a2;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;k=n*m;
	for(int i=1;i<=k;i++)cin>>a[i];
	a[0]=a[1];
	sort(a+1,a+k+1,cmp);
	while(a[p]!=a[0])p++;
	b=p%(2*n);
	x=p/(2*n)*2+(b>n ? 2 : (!b ? 0 : 1));
	y=((b>0 && b<=n) ? b : (!b ? 1 : 2*n+1-b));
	cout<<x<<' '<<y;
	return 0;
}
