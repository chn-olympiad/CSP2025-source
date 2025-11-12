#include<bits/stdc++.h>
using namespace std;
struct T{
	int x,id;
} a[105];
bool cmp(T x,T y){
	return x.x>y.x;
}
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int x=0,y=1,id=1;
	while(id<=n*m){
		while(x+1<=n&&a[id].id!=1) x++,id++;
		if(a[id].id==1){
			if(x+1>n) cout<<y+1<<' '<<x,exit(0);
			else cout<<y<<' '<<x+1,exit(0);
		}
		y++,id++;
		while(x-1>=1&&a[id].id!=1) x--,id++;
		if(a[id].id==1){
			if(x-1<1) cout<<y+1<<' '<<x,exit(0);
			else cout<<y<<' '<<x-1,exit(0);
		}
		y++,id++;
	}
	return 0;
}
