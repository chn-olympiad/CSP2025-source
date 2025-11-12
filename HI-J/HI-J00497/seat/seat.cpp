#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,pos,xr,yr;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	pos=1;
	xr=1;
	yr=1;
	while(a[pos]!=r){
		if(yr%2==1){
			xr++;
		}else{
			xr--;
		}
		if(xr>n){
			xr=n;
			yr++;
		}else if(xr<1){
			xr=1;
			yr++;
		}
		pos++;
	}
	cout<<yr<<" "<<xr;
	return 0;
}
