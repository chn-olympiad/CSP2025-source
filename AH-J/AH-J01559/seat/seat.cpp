#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xm=a[1];
	sort(a+1,a+1+n*m,cmp);
	int pm;
	for(int i=1;i<=n*m;i++){
		if(a[i]==xm){
			pm=i;
		}
	}
	int x=pm/(2*n)*2;
	int ys=pm%(2*n),y;
	if(ys<=n){
		y=ys;
		x++;
	}
	else{
		ys-=n;
		y=n-ys+1;
		x+=2;
	}
	cout<<x<<' '<<y;
	return 0;
}

