#include<bits/stdc++.h>
using namespace std;
bool _Compare(int x,int y){
	return x>y;
}
int zw[15][15];
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1;
	cin>>n>>m>>a1;
	a[1]=a1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,_Compare);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				zw[i][j]=a[(i-1)*n+j];
			}
		}
		else{
			for(int j=1;j<=n;j++){
				zw[i][j]=a[(i-1)*n+n-j+1];
			}
		}
	}
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<zw[j][i]<<' ';
		}
		cout<<endl;
	}
	*/
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(zw[i][j]==a1){
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}