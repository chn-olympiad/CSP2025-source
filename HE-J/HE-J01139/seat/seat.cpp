#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z;
	cin>>n>>m;
	int c[n*m];
	int a[n+1][m+1];
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	z=c[1];
	int s=0;
	for(int i=1;i<=n*m-1;i++){
		
		if(c[i]<c[i+1]){
			s=c[i];
			c[i]=c[i+1];
			c[i+1]=s;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
				a[j][i]=c[i];
	        if(c[i]==z==a[j][i]){
				cout<<j<<i<<endl;
			}
		}
}
	return 0;
} 
