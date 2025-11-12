#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[101][101],c,r,s,f[10001],h,x,y;
	cin>>c>>r;
	for(h=0;h<c*r;h++){
			cin>>f[h];}
		for(int i=0;i<c;i++){
		for(int j=0;i<r;j++){
			s=f[0];
			if(i<c-1){a[i][0]=f[h];}
			if(j<r-1){a[i-1][j++]=f[h];}
			}
		}
	for(int i=0;i<c;i++){
		for(int j=0;i<r;j++){
		while(a[i][j]!=s){
				x++;
				y++;}}}
	cout<<x<<y;
	return 0; 
}
