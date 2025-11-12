#include<bits/stdc++.h>
using namespace std;
int n,m,b1;
int a[14][14],b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&b[i]);
	}
	int c=n*m;
	b1=b[1];
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				a[i][j]=b[c];
				c--;
			}
		}else{
			for(int j=1;j<=m;j++){
				a[i][j]=b[c];
				c--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==b1){
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	return 0;
} 
