#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=2;i<=n*m;i++){
		cin>>y;
		if(y>x){
			cnt++;
		}
	}
	int nx=cnt/n,ny=cnt%n;
	if(nx*n!=cnt){
		nx++;
	}
	if(ny==0){
		ny=n;
	}
	if(nx%2==0){
		ny=n-ny+1;
	}
	cout<<nx<<' '<<ny;
	return 0;
}
