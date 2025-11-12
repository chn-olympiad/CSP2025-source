#include<bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,nm,p=0,xm;
	scanf("%d %d",&n,&m);
	nm=n*m;
	for(i=1;i<=nm;i++)
		scanf("%d",&a[i]);
	xm=a[1];
	sort(a+1,a+nm+1);
	for(i=1;i<=m;i++){
		if(p==0){
			for(j=1;j<=n;j++)
				b[j][i]=a[nm--];
		}
		else{
			for(j=n;j>=1;j--)
				b[j][i]=a[nm--];
		}
		p=(p+1)%2;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(b[i][j]==xm)
				printf("%d %d",j,i);
	return 0;
}
