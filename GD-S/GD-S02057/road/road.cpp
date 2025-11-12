#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,book[N][N],c[15],a[N],b[N][N],ans,bb[N][N],kk[N];
map<int,int> flag;
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	int u,v,w;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) book[i][j]=INT_MAX;
	} 	
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		book[v][u]=w;
		book[u][v]=book[v][u];
	}

	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			cin >> a[j];
			
			for(int ii=1;ii<j;ii++){
				if(book[j][ii]>=a[j]+a[ii]+c[i]) bb[j][ii]=c[i];
				book[j][ii]=min(book[j][ii],a[j]+a[ii]+c[i]),book[ii][j]=book[j][ii];
			} 
		}
	}
	for(int i=1;i<=n;i++){
		int x,y,z=INT_MAX;
		kk[i]=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(b[i][j]||kk[j]) continue;
			if(book[i][j]<z) z=book[i][j],x=i,y=j;
		}
		b[x][y]=1,b[y][x]=1;
		if(bb[x][y]){
			if(flag[bb[x][y]]) z-=bb[x][y];
			else flag[bb[x][y]]=1;
		}
		cout << y << endl;
		if(y==0) break;
		i=y;
		
		ans+=z;
	}
	cout << ans;
	return 0;
} 
