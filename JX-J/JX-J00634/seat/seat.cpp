#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int wa,da=1;
int x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>wa;
	for(int i=1;i<n*m;i++){
		cin>>q;
		if(q>wa){
			da++;
		}
	}
	x=(da-1)/n+1;
	if(x%2==1){
		y=da-(x-1)*n;
	}
	else{
		y=m-da%n+1;
	}
	cout<<x<<" "<<y;
    return 0;
}
