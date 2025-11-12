#include<bits/stdc++.h> 
using namespace std;
int wz[11][11];
int n,m;
int a[121];
int xr;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xr=a[1];
	int w=n*m;
	sort(a+1,a+n*m+1);
	
	
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int o=1;o<=m;o++){
				
			wz[o][i]=a[w];
			w--;
			}
		}else{
			for(int o=m;o>=1;o--){
				
			wz[o][i]=a[w];
			w--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int o=1;o<=m;o++){
			if(wz[i][o]==xr){
				cout<<o<<" "<<i;
			}
		}
	}
	return 0;
}
