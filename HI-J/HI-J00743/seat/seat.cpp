#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15],f[105];
int x,y=1,dis;
bool opt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int len=n*m;
	for(int i=1;i<=len;i++){
		scanf("%d",&f[i]);
		if(i==1){
			dis=f[i];
		}
	}
	sort(f+1,f+len+1,cmp);
	for(int i=1;i<=len;i++){
		if(opt==0){
			x++;
		}
		else{
			x--;
		}
		if(x==n+1){
			x=n;
			y++;
			opt=1;
		}
		else if(x==0){
			x=1;
			y++;
			opt=0;
		}
		a[x][y]=f[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==dis){
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0;
}
