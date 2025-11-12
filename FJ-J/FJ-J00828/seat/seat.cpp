#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1,xr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int r[n*m+5];
	int a[n+5][m+5];
	for(int i=1;i<=n*m;i++)
		cin>>r[i];
	xr=r[1];
	sort(r+1,r+n*m+1);
	for(int i=n*m;i>=1;i--){
		a[y][x]=r[i];
		if(y%2==1){
			if(x+1>n)	y++;
			else	x++;
		}else{
			if(x-1<1)	y++;
			else	x--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[j][i]==xr){
				cout<<j<<" "<<i;
				return 0;
			}
		} 
	} 
	return 0;
}
