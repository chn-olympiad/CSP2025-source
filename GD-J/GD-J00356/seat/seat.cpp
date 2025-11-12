#include<bits/stdc++.h>
using namespace std;
struct tt{
	int x,id;
}a[10005];
int y=1,z,h,n,m,x=1;
bool cmp(tt l,tt r){
	return l.x>r.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].x,a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1) cout<<x<<' '<<y,exit(0);
		if(x&1){
			y++;
			if(y>n) y=n,x++;
		}else{
			y--;
			if(y<1) y=1,x++;
		}
	}
	return 0;
} 
