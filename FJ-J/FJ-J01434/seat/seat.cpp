#include<bits/stdc++.h>
using namespace std;
int z[15][15],n,m,c=1,r=1,a[15][15],box;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int k=0;k<m;k++){
		for(int l=0;l<n;l++){
			if(a[k][l]>a[k][l-1]){
				r++;
				if(r>n){
					c++;
					r=1;
				}
			}
		}
	}
	cout<<c-2<<" "<<r+1;
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	return 0;
}
