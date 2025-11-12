#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int c[N][N];
bool in[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int u;
		
		scanf("%d",&u);
		c[x][y]=u;1
	}
	for(int i=0;i<=k;i++){
		int q;
		for(int j=0;j<=n;j++) scanf("%d",&q);
	}
	int ans=0;
	int mina=0x3f3f3f3f;
	int y=0;
	for(int i=1;i<=n;i++){
		mina=0x3f3f3f3f;
		if (in[i]){
			for(int j=n;j>0;j--){
				if(mina>c[i][j] and c[i][j]!=0){
					y=j;
					mina=c[i][j];
				for(int k=1;k<=n;k++){
					if (c[j][k]<mina) continue;
					}
				}
			}
			ans+=mina;
			in[i]=false;
			in[y]=false;
		}	
	printf ("%d",ans);	
	}
	return 0;
}
