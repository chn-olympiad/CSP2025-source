#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++,k++){
			b[j][i]=a[k];
		}
	}
	for(int i=2;i<=m;i+=2){
		for(int j=1;j<=n/2;j++){
			int t=b[j][i];
			b[j][i]=b[n-j+1][i];
			b[n-j+1][i]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r==b[i][j]){
				cout<<j<<' '<<i;
				exit(0);
			}
		}
	}
	return 0;
}
