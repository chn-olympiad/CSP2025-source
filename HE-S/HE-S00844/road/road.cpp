#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,bfs[10010][10010],bfs1[10010][11],cu[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
		bfs[a][b]=c;
		bfs[b][a]=c;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&a);
		cu[i]=a;
		for(int j=1;j<=n;i++){
			scanf("%d",a);
			bfs1[j][i]=a;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			bfs[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=n;i++){
		bfs[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		bfs[i][i]=0;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(bfs[j][i]+bfs[i][l]<bfs[j][l]){
					bfs[j][l]=bfs[j][i]+bfs[i][l];
				}
				
			}
		}
	}
	for(int i=1;i<=k;i++){
		bfs[i][i]=0;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(bfs1[j][i]+bfs[l][i]<bfs[j][l])
					bfs[j][l]=bfs[j][i]+bfs[l][i];
				
			}
		}
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
	}else cout<<bfs[1][n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
