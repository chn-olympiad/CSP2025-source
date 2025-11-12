#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200],k,x,y=1,dx[4]={1,0,-1,0},dy[4]={0,1,0,1},t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(ll i=n*m;i>=1;i--){
		if(x+dx[t%4]>n||x+dx[t%4]<1||t%4==1||t%4==3){
			t++;
		}
		x+=dx[t%4];
		y+=dy[t%4];
		if(a[i]==k){
			cout<<y<<' '<<x;
			return 0; 
		}
	}
	return 0;
}
