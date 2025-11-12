#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int maps[10005][10005];
int f[15][10005];
int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		maps[x][y]=z;
		maps[y][x]=z;
	}
	bool f1=0;
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		f[i][0]=x;
		if(x=0){
			f1=1; 
		}
		for(int j=1;j<=n;j++){
			int y;
			scanf("%d",&y);
			f[i][j]=y;
			f[j][i]=y;
			if(y){
				f1=1;
			}
		}
	}
	if(f1==0){
		printf("0");
		return 0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
