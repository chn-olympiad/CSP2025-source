#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],v[15][15],diyiwei,z;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	diyiwei=a[1];
	sort(a+1,a+n*m+1);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				v[i][j]=a[n*m-z];
				z++;
			}
		}else{
			for(int i=n;i>=1;i--){
				v[i][j]=a[n*m-z];
				z++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(v[i][j]==diyiwei){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
