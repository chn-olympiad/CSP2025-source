#include<bits/stdc++.h>
using namespace std;
int fs[105],pdd[15][15];
int n,m,xr,nx=1,my=1;
int pd(int rs){
	pdd[nx][my]=1;
	if(fs[rs]==xr){
		cout<<my<<" "<<nx;
	}
	if(nx-1>0&&pdd[nx-1][my]!=1){
		nx--;
		return pd(rs-1);
	}
	if(nx+1<=n&&pdd[nx+1][my]!=1){
		nx++;
		return pd(rs-1);
	}
	if(my+1<=m&&pdd[nx][my+1]!=1){
		my++;
		return pd(rs-1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>xr;
    fs[1]=xr;
	for(int i=2;i<=n*m;i++){
		cin>>fs[i];
	}
	sort(fs+1,fs+1+n*m);
	pd(n*m);
	return 0;
}
