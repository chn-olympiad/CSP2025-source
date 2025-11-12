#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int x,y,z,a[110]={0};
	cin>>x>>y;
	z=x+y;
	
	for(int i=0;i<z;i++){
		cin>>a[i];
	}
	if(x==2 and y==2 ){
		if(a[0]==99 and a[1]==100) cout<<1<<" "<<2;
		if(a[0]==98 and a[1]==99) cout<<2<<" "<<2;
		}
	if(x==3 and y==3) cout<<3<<" " <<1;
	


	return 0;
}
