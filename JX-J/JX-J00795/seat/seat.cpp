#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<n*m;i++){
		int a;
		cin>>a;
		if(a>r){
			if(x%2==1) y++;
			else y--;
			if(y>n){
				x++;
				y=n;
			}
			if(y<1){
				x++;
				y=1;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
