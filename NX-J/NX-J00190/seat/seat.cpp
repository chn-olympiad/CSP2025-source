#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000],k,mp[1000][1000],y=1,pos,xx,yy;
void up(){
	int x=n;
	while(x>=1){
		k++;
		mp[x][y]=a[k];
		if(a[k]==pos){
			xx=x;
			yy=y;
		}
		x--;
	}
	y++;
}
void down(){
	int x=1;
	while(x<=n){
		k++;
		mp[x][y]=a[k];
		if(a[k]==pos){
			xx=x;
			yy=y;
		}
		x++;
	}
	y++;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	pos=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	while(1){
		down();
		if(y>m)break;
		up();
		if(y>m)break;
	}
	cout<<yy<<" "<<xx;
	return 0;
}
