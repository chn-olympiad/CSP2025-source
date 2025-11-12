#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt=1,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) cnt++; 
	}
	y=int(cnt/n)+1;
	if((cnt/n)%2==0) x=0+cnt%n;
	else x=n+1-(cnt%n);
	if(x==0){
		y--;
		x=1;
	}
	if(x==n+1){
		y--;
		x=n;
	}
	cout<<y<<' '<<x;
	return 0;
}