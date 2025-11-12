#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+1+m*n,greater<int>());
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			b[i][j]=a[(i-1)*n+j];
		}
	}
	for(int i=2;i<=m;i+=2){
		for(int j=1;j<=n/2;j++){
			swap(b[i][j],b[i][n+1-j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[j][i]==R){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}

