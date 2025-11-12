#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int r[10000][10000],a[10000];
bool kd[10000];
int f[100000][2];
void dfs(int s){
	kd[s]=1;
	for(int i=1;i<=n;i++){
		if(r[s][i]==-1) continue;
		if(kd[i] && i>n){
			if(f[i][0]>f[s][0]+r[s][i]){
				f[i][0]=f[s][0]+r[s][i]-a[i];
				f[i][1]=r[s][i]-a[i];
				dfs(i);
			}
		}
		else if(!kd[i] && i>n){
			f[i][0]=f[s][0]+r[s][i];
			f[i][1]=r[s][i];
			dfs(i);
		}
		else if(kd[i] && i<=n){
			if(f[i][0]>f[s][0]+r[s][i]){
				f[i][0]=f[s][0]+r[s][i];
				f[i][1]=r[s][i];
				dfs(i);
			}
		}
		else{
			f[i][0]=f[s][0]+r[s][i];
			f[i][1]=r[s][i];
			dfs(i);
		}
	}
	return ;
}
int main(){
	freopen("road.out","r",stdin);
	freopen("road.in","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n+k;i++){
		f[i][0]=-1;
		f[i][1]=-1;
		for(int j=1;j<=n+k;j++){
			r[i][j]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		r[u][v]=w;
		r[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int u,v,w;
		scanf("%d",&a[i]);
		for(int j=1;j<=n;j++){
			cin>>w;
			r[n+i][j]=a[i]+w;
			r[j][n+i]=a[i]+w;
		}
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		ans+=f[i][1];
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

