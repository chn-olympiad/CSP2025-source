#include<bits/stdc++.h>
using namespace std;
int n,m,b,a[11000],x,y,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		cnt++;
		if(a[i]==b){
			break;
		}
	}
	x=cnt/n;
	y=cnt%n;
	if(y!=0){
		x++;
	}
	if(y==0){
		y=n;
	}
	if(x%2==0){
		int yy=n-y+1;
		y=yy;
	}
	cout<<x<<" "<<y;
	return 0;
}
