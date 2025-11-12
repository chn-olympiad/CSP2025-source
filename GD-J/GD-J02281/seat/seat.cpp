#include<bits/stdc++.h>
using namespace std;
int n,m,z,k[105],a[15][15],x=1,y=1,l;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			a[i][j]=0;
			scanf("%d",&k[++z]);
			if(i==1 && j==1) {
				l=k[z];
			}
		}
	}
	sort(k+1,k+1+z);
	for(int i=z; i>=1; i--) {
		a[x][y]=k[i];
		if(k[i]==l){
			printf("%d %d\n",y,x);
			break;
		}
		if(x+1<=n && a[x+1][y]==0) x++;
		else if(x-1>=1 && a[x-1][y]==0) x--;
		else y++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
