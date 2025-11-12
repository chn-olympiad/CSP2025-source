#include<bits/stdc++.h>
using namespace std;
int n,m;
int r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+1];
	cin>>r;
	a[1]=r;
	int cnt=1,x=0,y=0;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>r) cnt++;
	}
	if(cnt<=n){
		cout<<1<<' '<<cnt;
		return 0;
	}
	x=cnt%n;
	y=cnt/n;
	if(x!=0) y++;
	if(y%2!=0){
		cout<<y<<' '<<x;
	}else{
		cout<<y<<' '<<n-x+1;
	}
	return 0;
}
