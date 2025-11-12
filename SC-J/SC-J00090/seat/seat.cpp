#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[101];
int fd;
int cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>f[i];
	}
	fd=f[1];
	sort(f+1,f+1+n*m,cmp);
	int x=1,y=1,at=1;
	int js=1;
	while(f[at]!=fd){
		at++;
		y+=js;
		if(y<1||y>n){
			x++;
			y-=js;
			js=-js;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}