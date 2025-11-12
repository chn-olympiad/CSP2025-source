#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105],x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n*m);
	int h=1;
	for(int i=n*m-1;i>=0;i--){
		if(b[i]==a[0]){
			break;
		}
		h++;
	}
	h--;
	for(int i=0;i<h;i++){
		if(y%2==1){
			if(x<n) x++;
			else{
				y++;
			} 
		}
		else {
			if(x>1) x--;
			else{
				y++;
			} 
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
