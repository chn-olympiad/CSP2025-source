#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],b[150],c[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1;i<=n*m;i++){
		b[i]=a[n*m-i+1];
	}
	int h=1,l=1,s=1;
	while(h<=n){
		for(int i=1;i<=m;i++){
			c[i][h]=b[s];
			s++;
		}
		h++;
		if(h>n)break;
		for(int i=m;i>=1;i--){
			c[i][h]=b[s];
			s++;
		}
		h++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==r)cout<<j<<" "<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 