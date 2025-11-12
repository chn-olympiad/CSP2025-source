#include <bits/stdc++.h>
using namespace std;
int n,m,a[150],c,d=1,x=1,y=1;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>c;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>c){
			d++;
		}
	}
	while(d>1){
		if(x%2==1){
			if(y<m){
				y++;
			}
			else {
				x++;
			}
		}
		else {
			if(y>1){
				y--;
			}
			else {
				x++;
			}
		}
		
		d--;
	}
	cout<<x<<" "<<y;
	
	return 0;
}