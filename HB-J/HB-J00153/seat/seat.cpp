#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
ll n=0,m=0,r=0,x=1,y=1;
int a[99000]={};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	a[1]=r;
	for(ll i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(ll i=1;i<=n*m;i++){
		if(a[i]==r){
			 r=i;
			 break;
		 }
	}
	bool f=1;
	for(ll i=2;i<=r;i++){
		if(f)x++;
		if(!f)x--;
		if(x-1==n){
			y++;
			f=0;
			x=n;	
		}
		if(x==0){
			y++;
			f=1;
			x=1;	
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
