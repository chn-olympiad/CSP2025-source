#include<bits/stdc++.h>
using namespace std;
int a[101],b[101],c[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s1,s2;
	cin>>n>>m;
	for(int i=0;i<=n*m-1;i++){
		cin>>a[i];
	}
	int t=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		b[m*n-1-i]=a[i];
	}
	int v=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				c[j][i]=b[v];
				v++;
			}
		}
		else {
			for(int j=n;j>=1;j--){
				c[j][i]=b[v];
				v++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]==t)cout<<j<<" "<<i;
		}
	}

	
	return 0;
}