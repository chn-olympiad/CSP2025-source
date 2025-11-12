#include<bits/stdc++.h>
using namespace std;
int a[200],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	sort(a+1,a+n*m+1);
	int x=1,y=1,dx=1,dy=0;
	for(int i=n*m;i>=1;i--){
		if(a[i]==cnt){
			cout<<y<<" "<<x;
			break;
		}
		if(x==n){
			if(y%2==1){
				dx=0;
				dy=1;
			} else {
				dx=-1;
				dy=0;
			}
		} else if(x==1){
			if(y%2==1){
				dx=1;
				dy=0;
			} else {
				dx=0;
				dy=1;
			}
		} else {
			if(y%2==1){
				dx=1;
				dy=0;
			} else {
				dx=-1;
				dy=0;
			}
		}
		x+=dx;
		y+=dy;
	}
	return 0;
}
