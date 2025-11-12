#include<bits/stdc++.h>
using namespace std;
int vui[105],a[105],b[11][11],xr,c=0;
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int k=1;k<=n*m;k++) scanf("%d",&vui[k]);
	xr=vui[1];
	sort(vui+1,vui+n*m+1);
	for(int k=n*m;k>=1;k--){
		a[k]=vui[n*m-k+1];
		if(vui[n*m-k+1]==xr){
			xr=k;
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				++c;
				if(c==xr) cout<<i<<" "<<j;
			}
		}
		if(i%2==0){
			for(int j=m;j>=1;j--){
				++c;
				if(c==xr) cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}