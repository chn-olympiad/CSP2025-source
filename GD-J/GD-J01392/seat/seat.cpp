#include<bits/stdc++.h>
using namespace std;
int n,m,nn,nu,cnt,c[111],ni,b[111],a[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	nu=b[1];
	sort(b+1,b+1+n*m);
	for(int i=1;i<=n*m;i++){
		c[i]=b[n*m-i+1];
	}
	for(int i=1;i<=n*m;i++){
		b[i]=c[i];
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				cnt++;
				a[j][i]=b[cnt];
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				cnt++;
				a[j][i]=b[cnt];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(nu==a[i][j])cout<<j<<' '<<i;
		}
	}
	return 0;
}
