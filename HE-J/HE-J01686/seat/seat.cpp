#include<bits/stdc++.h>
using namespace std;
int a[1000],b[100][100];
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=a[1];
	sort(a+1,a+(n*m)+1);
	int d=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[i][j]=a[d];
				d--;
			}
		}
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				b[i][j]=a[d];
				d--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==c){
				cout<<i<<" "<<j;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
