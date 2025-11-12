#include<bits/stdc++.h>
using namespace std;
int h,l,z,w,ah,al,y;
int a[105],b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>h>>l;
	for(int i=0;i<h*l;i++){
		cin>>a[i];
	}
	z=a[0];
	sort(a+0,a+(h*l+1));
	for(int i=0;i<h*l;i++){

		if(a[i]==z){
			w=h*l-i;
			if((i%h+1)%2==0)ah=h-(i/h);
			if((i%h+1)%2!=0)ah=(h+1)-(i/h);
			al=i%h+1;
			break;
		}
	}
	cout<<ah<<" "<<al;
	return 0;
}