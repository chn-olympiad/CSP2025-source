#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	for(int i=1;i<=n*m;i++){
			for(int j=i+1;j<=n*m;j++){
				if(a[i]<a[j]){
			       swap(a[i],a[j]);
		        }
			}
    }
	int c[15][15];
	int d=1;
	for(int y=1;y<=m;y++){
		if(y%2!=0){
			for(int j=1;j<=n;j++){
				c[j][y]=a[d];
				d++;
		    }
		}
		else{
			for(int k=n;k>=1;k--){
				c[k][y]=a[d];
				d++;
		    }
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b==c[i][j]){
				printf("%d",j);
				cout<<" ";
				printf("%d",i);
			}
		}
	}
	return 0;
}
