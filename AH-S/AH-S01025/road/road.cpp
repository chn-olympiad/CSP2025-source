#include<bits/stdc++.h>
using namespace std;
int const N=1e4;
int n,m,k,cnt;
int w[N][N],c[N];
int a[N][N];
bool vis[N][N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int u1,v1,w1;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u1,&v1,&w1);
        w[u1][v1]=w1;
        w[v1][u1]=w1;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n-1;j++){
            cin>>a[i][j];
            vis[i][j]=1;
            vis[j][i]=1;
        }
    }
    for(int i=1;i<=n;i++){
		int f=0;
		for(int j=1;j<=n;j++){
			if(vis[i][j]==1){
				f=1;
			}
		}
		if(f==0){
			int min0=1000000000;
			for(int p=1;p<=n;p++){
				if(w[i][p]<min0){
					min0=w[i][p];
				}
			}
			cnt+=min0;
		}
	}
	cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


