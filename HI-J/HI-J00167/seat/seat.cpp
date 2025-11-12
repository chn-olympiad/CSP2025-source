#include<bits/stdc++.h>
using namespace std;
int a[10086];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int qqq=1;
	for(int i=2;i<=m*n;i++){
		if(a[1]<a[i])qqq++;
	}
	int f[100][100];
	for(int i=1;i<=m;i+=2){
		int qwertyuiop=1;
		for(int j=1;j<=n;j++){
			f[i][j]=a[qwertyuiop];
			qwertyuiop++;
		}
		for(int j=n;j>=1;j--){
			f[i][j]=a[qwertyuiop];
			qwertyuiop++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]==qqq)cout<<i<<j;
		}
	}
	return 0;
}
