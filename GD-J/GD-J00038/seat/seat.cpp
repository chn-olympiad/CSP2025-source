#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,c[110],xr,a[20][20],k=1,h,l;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)cin>>c[i];
	xr=c[1];
	sort(c+1,c+n*m+1,cmp);
	for(ll j=1;j<=m;j++){
		if(j%2==1){
			for(ll i=1;i<=n;i++){
				a[i][j]=c[k];
				k++;
			}	
		}else{
			for(ll i=n;i>=1;i--){
				a[i][j]=c[k];
				k++;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(a[i][j]==xr)h=i,l=j;
		}
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
