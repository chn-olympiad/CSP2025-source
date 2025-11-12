#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+5;
const int mod=1e9+7;
int a[105][105],n,m,peo,b[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i];
	peo=b[1];
	sort(b+1,b+n*m+1);
	int g=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=b[g];
				g--;
			}
		}
		else {
			for(int j=n;j>=1;j--){
				a[j][i]=b[g];
				g--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==peo){
				cout<<j<<" "<<i;
				return 0;
			}
		//	cout<<a[i][j]<<" ";
		}
	//	cout<<'\n';
	}
	return 0;
}