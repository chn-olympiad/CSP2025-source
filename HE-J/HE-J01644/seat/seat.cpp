#include <bits/stdc++.h>
using namespace std;
const int N=15,M=15,SC=105;
int seat[N][M],a[SC];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int stucut=1,lm=1;
	while(m>lm){
		for(int i=1;i<=n;i++){
			seat[i][lm]=a[stucut];
			stucut++;
		}
		lm++;
		for(int i=n;i>=1;i--){
			seat[i][lm]=a[stucut];
			stucut++;
		}
		lm++;
	}
	if(m%2==1){
		for(int i=1;i<=n;i++){
			seat[i][m]=a[stucut];
			stucut++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==r){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}

