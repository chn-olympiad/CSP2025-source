#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin)
	freopen("seat.out","w",stdin)
	int n,m,c;
	int a[1000],b[1000][1000],d[5];
	cin>>n,m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++){
		for(int j=1;j<=n*m;j++){
			if(b[k][i]>a[j]){
				b[k][i]=a[j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==c){
				d[1]=i;
				d[2]=j;
			}
		}
	}
	d[3]=d[1];
	if(d[1]%2==0){
		d[3]=m-d[1]+1;
	}
	cout<<d[3]<<d[2];
	return 0;
}
