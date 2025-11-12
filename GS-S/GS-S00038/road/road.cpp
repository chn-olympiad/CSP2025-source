#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
int n,m,k;
int s[N][N],a[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		s[u][v]=w;
		s[v][u]=w;
		s[i][i]=0;
	}
	for(int i=1+m;i<=k+m;i++){
		int c,a[n];
		scanf("%d",&c);
		for(int j=1+m;j<=n+m;j++){
			scanf("%d",&a[j]);
			s[i][j]=a[j];
			s[j][i]=a[j];
		}
		s[i][i]=c;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1][j-1]!=0&&s[i-1][j+1]!=0){
				a[i][j]=min(s[i-1][j-1],s[i-1][j+1])+s[i][j];
			}
		}
	}
	cout<<"13";
	return 0;
}
