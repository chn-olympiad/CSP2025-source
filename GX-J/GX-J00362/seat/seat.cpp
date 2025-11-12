#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int n,m,a[1010],b[15][15];
	cin>>n>>m;
	int x=m*n;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	int r=a[1],l=0;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=x-i;j++){
			if(a[j]<a[j+1]){
				int y=a[j];
				a[j]=a[j+1];
				a[j+1]=y;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(m%2==1){
			for(int j=1;j<=n;j++){
				l++;
				b[i][j]=a[l];
			}
		}
		if(m%2==0){
			for(int j=n;j>=1;j--){
				l++;
				b[i][j]=a[l];
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(m%2==1){
			for(int j=1;j<=n;j++){
				if(b[i][j]==r){
				cout<<i<<" "<<j;
				return 0;
				}
			}
		}
		if(m%2==0){
			for(int j=n;j>=1;j--){
				if(b[i][j]==r){
				cout<<i<<" "<<j;
				return 0;
				}
			}
		}
	}
	return 0;
}
