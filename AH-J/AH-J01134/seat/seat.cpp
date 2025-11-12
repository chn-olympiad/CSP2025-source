#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st{
	ll pm,x,td;
}a[200];
struct zy{
	ll x,y;
}c[20][20];
ll n,m,rpm,rx,rtd,t,x[20][20];
bool cmp(const st &x,const st &y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i].x;
		if(i==1){
			rx=a[i].x;
		}
	}
	sort(a+1,a+1+n*m,cmp);
	t=1;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			x[i][j]=a[t++].x;
			c[i][j].x=i;
			c[i][j].y=j;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(x[i][j]==rx){
				if(i%2==1){
					cout<<c[i][j].x<<' '<<c[i][j].y;
				}
				if(i%2==0){
					cout<<c[i][m-j+1].x<<' '<<c[i][m-j+1].y;
				}
			}
		}	
	}
	return 0;
}
