#include<bits/stdc++.h>
using namespace std;
void inti(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
int n,m;
double rp;
double a[101];
void dfs(int x,int y,int dx,int id){
	if(a[id]==rp){
		cout<<x<<' '<<y;
		return ;
	}
	y+=dx;
	if(y<1){
		dx=1;
		y=1,++x;
	}
	if(y>n){
		dx=-1;
		y=n,++x;
	}
	dfs(x,y,dx,id+1);
}
signed main(){
	inti();
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	rp=a[1];
	sort(a+1,a+1+n*m,greater<double>());
	dfs(1,1,1,1);
	return 0;
}
