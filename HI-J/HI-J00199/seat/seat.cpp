#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1);
	int j=1,l=n*m;
	for(int i=1;i<=n;i++){
		if(j==0) j=1;
		if(j==m+1) j=m;
		if(j==1){
			for(j;j<=m;j++){
				b[i][j]=a[l];
				l--;
			}
		}else{
		    for(j;j>=1;j--){
				b[i][j]=a[l];
				l--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==t){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
