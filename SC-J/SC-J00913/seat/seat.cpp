#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct seat{
	int p,x,y;
}a[105];
bool cmp(seat x,seat y){
	return x.p>y.p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].p;
	int temp=a[1].p;
	sort(a+1,a+n*m+1,cmp);
	int dx=1,dy=1,t=1;
	a[1].x=1;
	a[1].y=1;
	for(int i=2;i<=n*m;i++){
		if(dx==n&&dy%2==1){
			t=-1;
			dy++;
		}
		else if(dx==1&&dy%2==0){
			t=1;
			dy++;
		}
		else dx+=t;
		a[i].x=dx;
		a[i].y=dy;
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].p==temp){
			cout<<a[i].y<<" "<<a[i].x;
			return 0;
		}
	}
	return 0;
} 