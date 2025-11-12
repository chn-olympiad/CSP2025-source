#include<bits/stdc++.h>
using namespace std;
int a[400],b[400],c[20][20],m,n,s,w,v;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	v=a[1];
	for(int i=1;i<=m*n;i++){
		for(int j=1;j<=m*n;j++){
			if(a[j]>b[i]){
				b[i]=a[j];
				s=j;
			}
		}
		a[s]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				w=n*(i-1)+j;
				c[i][j]=b[w];
			}
			else if(i%2==0){
				w=n*i-j+1;
				c[i][j]=b[w];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]==v){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}