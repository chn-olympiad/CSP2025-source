#include<bits/stdc++.h>
using namespace std;
int n, m, ii=1, jj=1, sum, a[105], f[15][15];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n*m; i++){
		scanf("%d", &a[i]);
	}
	sum=a[1];
	sort(a+1, a+1+n*m);
	f[ii][jj]=a[n*m];
	for(int k=n*m-1; k>=1; k--){
		if(ii+1<=n && f[ii+1][jj]==0){
			ii++;
			f[ii][jj]=a[k];
		}else if(ii-1>=1 && f[ii-1][jj]==0){
			ii--;
			f[ii][jj]=a[k];
		}else if(jj+1<=m && f[ii][jj+1]==0){
			jj++;
			f[ii][jj]=a[k];
		}
		if(a[k]==sum){
			cout<<jj<<" "<<ii;
			return 0;
		}
	}
	return 0;
}

