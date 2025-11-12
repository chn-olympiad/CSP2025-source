#include<bits/stdc++.h>
using namespace std;
int n,m;
bool c(int x,int y){
	return x>y;
}
int a[105],b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	sort(a+1,a+n*m+1,c);
	
	int s=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s++;		
			b[i][j]=a[s];
		}
	}
	for(int i=2;i<=n;i+=2){
		for(int j=1;j<=m/2;j++){
			for(int k=m;k>m/2;k--){
				swap(b[i][j],b[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==cnt){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
} 
