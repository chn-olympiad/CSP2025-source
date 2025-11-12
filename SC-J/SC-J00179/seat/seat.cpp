#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[102],k,b[15][15];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}k=a[1];
	int z=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				b[i][j]=a[z];
			}else{
				b[i][n-j+1]=a[z];
			}z++;
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==k){
				cout<<i<<' '<<j;
				break;
			}
		}
	}return 0;
}