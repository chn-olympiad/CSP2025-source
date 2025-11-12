#include<bits/stdc++.h>
using namespace std;
long long n,m,cj[121];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>cj[i];
	long long xr=cj[1];
	sort(cj+1,cj+n*m+1);long long zz=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(cj[zz]==xr){
					cout<<i<<' '<<j;
					return 0;
				}zz--;
			}
		}
		if(i%2==0){
			for(int j=n;j>0;j--){
				if(cj[zz]==xr){
					cout<<i<<' '<<j;
					return 0;
				}zz--;
			}
		}
	}
	return 0;
}
