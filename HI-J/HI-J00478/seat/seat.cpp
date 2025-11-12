#include<bits/stdc++.h>
using namespace std;
//const int N_MAX=1e5+5;
int a[1000];
int b[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=1;j<n*m;j++){
			if(a[j-1]<a[j]){
				int x=a[j-1];
				a[j-1]=a[j];
				a[j]=x;
			}
		}
	}
//---------------------------------------------------------以上无问题---------------------------------------------- 
	int u=0;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>0;j--){
				b[j][i]=a[u];
				u++;
			}
		}else{
			for(int j=1;j<=n;j++){
				b[j][i]=a[u];
				u++;
			}
			
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==r){
				cout<<j<<" "<<i;
				return 0;
			}
			
		}
	}
	return 0;
}
/*3 3 
94 95 96 97 98 99 100 93 92*/

