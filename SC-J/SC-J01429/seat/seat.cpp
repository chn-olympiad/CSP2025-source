#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005][1005];
int bmp(int a1,int b1){
	return a1>b1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,bmp);
	int num=1;
	for(int i=1;i<=n;i++){
		num=i;
		for(int j=1;j<=m;j+=2){
			b[i][j]=a[num];
			num+=2*n;
		}
	}
	
	for(int i=1;i<=n;i++){
		num=2*n-i+1;
		for(int j=2;j<=m;j+=2){
			b[i][j]=a[num];
			num+=2*n;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==r){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 