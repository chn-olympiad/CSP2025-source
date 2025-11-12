#include <bits/stdc++.h>
using namespace std;
int z[15][15],n,m,r[105],l,d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>r[i];
	}
	d=r[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(r[j+1]>r[j]){
				l=r[j+1];
				r[j+1]=r[j];
				r[j]=l;
			}
		} 
	}
	int e=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			z[i][j]=r[e];
			if(r[e]==d){
				cout<<i<<" "<<j;
			}
			e++;
		}
	}
	return 0;
} 
