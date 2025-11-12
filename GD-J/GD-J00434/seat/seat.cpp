#include<bits/stdc++.h>
using namespace std;
int z[10][10],n,m,cj[100],r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	} 
	r=cj[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m-i+1;j++){
			if(cj[j]<cj[j+1]){
				int t=cj[j];
				cj[j]=cj[j+1];
				cj[j+1]=t;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j%2==0){
				z[i][j]=cj[(j)*n-i+1];
			}
			else{
				z[i][j]=cj[(j-1)*n+i];
			}
			if(z[j][i]==r){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
} 
