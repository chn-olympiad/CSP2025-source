#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],b[15][15],x,s=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	x=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]<a[j+1]){
				int t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	for(int j=1;j<=m;j++){
		if(j%2==1)
		for(int i=1;i<=n;i++){
			s++;
			b[i][j]=a[s];
		}
		else
		for(int i=n;i>=1;i--){
			s++;
			b[i][j]=a[s];
		} 
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[j][i]==x)printf("%d %d",i,j);
		}
	}
	return 0;
} 