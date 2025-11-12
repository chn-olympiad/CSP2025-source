#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,r,x,y,c=0;
	cin>>r;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>r){
			c++;
		}
	}
	x=c/n+1;
	y=(x&1)?(c%n+1):(n-c%n);
	cout<<x<<" "<<y;
	return 0;
}
 
