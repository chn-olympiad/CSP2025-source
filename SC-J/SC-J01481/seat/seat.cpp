#include<bits/stdc++.h>
using namespace std;
int a[111];
int main(){
	int n,m,ming,b,x,ys,y;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int r=n*m;
	for(int i=1;i<=r;i++){
		cin>>a[i];
	} 
	ming=a[1];
	sort(a+1,a+1+r);
	for(int i=1;i<=r;i++){
		if(a[i]==ming){
			b=r-i+1;
			break;
		} 
	}
	x=(b+n-1)/n;
	ys=b%(2*n);
	if(ys==0)	y=1;
	if(ys<=n&&ys!=0)	y=ys;
	if(ys>n) y=2*n-ys+1;
	cout<<x<<" "<<y;
	
} 