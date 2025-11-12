#include<bits/stdc++.h>
using namespace std;
int a[10000];
int c[100][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n*m;i++){
		cin >>a[i];
	}
	int p=a[1];
	sort(a+1,a+1+n*m);
	int o=n*m;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				c[i][j]=a[o];
				o--;
			}
		}
		if(j%2==0){
			for(int i=n;i>=1;i--){
				c[i][j]=a[o];
				o--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==p){
				cout <<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
} 
