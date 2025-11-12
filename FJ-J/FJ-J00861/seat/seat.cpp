#include <bits/stdc++.h>
using namespace std;
int n,m,x;
int k,i,j;
bool f;
int a[105],d[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int k=1;k<=n*m;k++) scanf("%d",&a[k]);
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	i=1,j=1;
	d[1][1]=a[1];
	for (int k=2;k<=n*m;k++){
		if (f==0){
			if (i==m){
				j++;
				d[i][j]=a[k];
				f=1;
			}
			else{
				i++;
				d[i][j]=a[k];
			}
		}
		else if (f==1){
			if (i==1){
				j++;
				d[i][j]=a[k];
				f=0;
			}
			else{
				i--;
				d[i][j]=a[k];
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (d[i][j]==x){
				printf("%d %d\n",j,i);
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
