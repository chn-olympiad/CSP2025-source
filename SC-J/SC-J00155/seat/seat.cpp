#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N];
int f[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]),a[i]=-a[i];
	int r=a[1];
	sort(a+1,a+1+n*m);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		f[x][y]=a[i];
		if(x%2==1){
			y++;
			if(y>m) x++,y--;
		}
		else{
			y--;
			if(y<=0) x++,y++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r==f[i][j]) printf("%d %d",i,j);
		}
	}
	return 0;
}