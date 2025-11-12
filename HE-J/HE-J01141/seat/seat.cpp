#include<bits/stdc++.h> 
using namespace std;
int n,m,k,x;
int a[105];
int b[15][15];
int c[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int y=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>0;i--){
		k++;
		c[k]=a[i];
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				x++;
				b[i][j]=c[x];
			}
		}else{
			for(int j=n;j>0;j--){
				x++;
				b[i][j]=c[x];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(y==b[i][j]){
				cout<<i<<" "<<j;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
