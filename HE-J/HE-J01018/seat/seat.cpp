#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],pm=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			pm++;
		}
	}
	int x=1,y=1;
	bool b=1;
	for(int i=1;i<pm;i++){
		if(b){
			if(x==n){
				y++;
				b=0;
				x--;
			}
			x++;
		}
		else{
			if(x==1){
				y++;
				b=1;
				x++;
			}
			x--;
		}
	}
	cout<<y<<" "<<x;
}
