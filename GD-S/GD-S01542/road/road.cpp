#include <bits/stdc++.h>
using namespace std;
int n,m,k,cnt;
int vis[10006];
int g[1006][1006];
int b[1000006],usm[1000006],vsm[1000006];
int lb[1000006],lusm[1000006],lvsm[1000006];
int ca[1706][1006],C[1706];
int h[1006][1006];
void dfs(int u){
	vis[u]=1;
	for (int v=1;v<=n;v++) if (h[u][v]!=-1 && !vis[v]){
		cnt+=h[u][v];
		dfs(v);
	}
}
bool check(){
	memset(vis,0,sizeof(vis));
	cnt=0;
	dfs(1);
	for (int i=1;i<=n;i++) if (vis[i]==0){
		cnt=0;
		return false;
	}
	return true;
}
int djstl(){
	int i=1;
	memset(h,-1,sizeof(h));
	while (b[i]!=-1){
		h[lusm[i]][lvsm[i]]=h[lvsm[i]][lusm[i]]=lb[i];
		if (check()){
			return cnt;
		}
		i++;
	}
}
int chooseCity(int cur,int ansgot,int yesorno){
	if (cur>k){
	for (int i=1;i<=m;i++){
		int tmp=upper_bound(lb+1,lb+m+1,b[i])-lb;
		if (lb[tmp]==-1){
			lb[tmp]=b[i];
			lusm[tmp]=usm[i];
			lvsm[tmp]=vsm[i];
			continue;
		}
		int tmp1,j=tmp+1;
		tmp1=lb[j];
		while (lb[j]!=-1){
			swap(lb[j+1],tmp1);
		}
		lb[tmp]=b[i];
		lusm[tmp]=usm[i];
		lvsm[tmp]=vsm[i];
	}
	return djstl();
	}
	if (yesorno==0) return min(chooseCity(cur+1,ansgot,0),chooseCity(cur+1,ansgot,1));
	int anss=C[cur];
	for (int i=1;i<=n;i++){
		int tmp;
		for (int j=1;j<=m;j++) if (cur==lusm[j]){
			if (lvsm[j]==i) b[j]=ca[cur][i];
			else{
				int opp=upper_bound(lusm+1,lusm+1000004,0)-lusm;
				lusm[opp]=cur;
				lvsm[opp]=i;
				b[opp]=ca[cur][i];
			}
		}else{
				int opp=upper_bound(lusm+1,lusm+1000004,0)-lusm;
				lusm[opp]=cur;
				lvsm[opp]=i;
				b[opp]=ca[cur][i];
			}
	}
	return min(chooseCity(cur+1,ansgot,0),chooseCity(cur+1,ansgot,1));
}
int main(){
	memset(g,-1,sizeof(g));
	memset(lb,-1,sizeof(lb));
	memset(b,-1,sizeof(b));
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u][v]=g[v][u]=w;
		b[i]=w;usm[i]=u;vsm[i]=v;
	}
	for (int i=1;i<=k;i++){
		int c;
		cin >> c;
		for (int j=1;j<=n;j++){
			int a;
			cin >> a;
			ca[i][j]=a;
			C[i]=c;
//			if (g[i]][j]!=-1) g[i][j]=g[j][i]=min(g[i][j],a+c);
//			else g[i][j]=g[j][i]=a+c;
		}
	}
	cout << min(chooseCity(1,1e9,0),chooseCity(1,1e9,1)) << endl;
	return 0;
}
