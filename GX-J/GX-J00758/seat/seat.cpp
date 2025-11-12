#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,r;
	cin>>x>>y;
	int a[x*y];
	cin>>r;   
	a[0]=r;                     
	for(int i=1;i<x*y;i++) cin>>a[i];
	sort(a,a+x*y);
	int yy,xx;
	for(int i=0;i<x*y;i++){
		if(r==a[i]) {
			i=x*y-i;
			if(i%x==0) xx=i/x;
			if(i%x!=0) xx=i/x+1;
			if(xx%2!=0) yy=i%x;
			if(xx%2==0) yy=x-(i%x+1);
			if(yy==0) yy=x;
			break;
		}
	}
	cout<<xx<<" "<<yy;
	return 0;
}
