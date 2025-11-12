#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c,r,i,j,pd,fuck,a[111],seat[11][11],step=1;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	fuck=a[1];
	cin>>c>>r;
	sort(a+1,a+n*m+1,cmp);
	for(j=1;j<=m;j++){
		if(pd%2==0){
			for(i=1;i<=n;i++){
				seat[j][i]=a[step++];
			}
		}else{
			for(i=n;i;i--){
				seat[j][i]=a[step++];
			}
		}
		pd++;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(seat[i][j]==fuck){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
