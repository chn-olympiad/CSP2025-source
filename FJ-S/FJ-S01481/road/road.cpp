#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,hp,tp,htd=1e9+5,cnt,ans,x,y,z,cc,summ;
int tow[10020],dis[10020],v[10020][10020];
int des[1100005],val[1100005];
void dfs(int cnt,int p,int summ){
	if(cnt>=n){
		ans=min(ans,summ);
		return;
	}
	for(int i=1;i<=n+k;i++){
		if(v[p][i] && !dis[i]){
			if(i<=n){
				summ+=v[p][i];
				dis[i]=1;
				dfs(cnt+1,i,summ);
				dis[i]=0;
				summ-=v[p][i];
			}else{
				summ+=v[p][i]+tow[i];
				int tt=tow[i];
				tow[i]=0;
				dis[i]=1;
				dfs(cnt,i,summ);
				dis[i]=0;
				tow[i]=tt;
				summ-=v[p][i]+tow[i];
			}
		}
	}
	return;
}
signed main(){
	//freopen("road1.in","r",stdin);
	//freopen("road1.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		v[x][y]=z;
		v[y][x]=z;
		if(z<=htd){
			htd=z;
			hp=x;
		}
	}	
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		tow[i+m]=x;
		for(int j=1;j<=n;j++){
			cin>>v[m+i][j];
			v[j][m+i]=v[m+i][j];
			if(v[j][m+i]+x<=htd){
				hp=j;
				htd=v[j][m+i]+x;
			}
		}
	}
	ans=1e9+5,dis[hp]=1,dis[tp]=1;
	for(int i=1;i<=n+k;i++){
		if(v[hp][i]){
			cc++;
			des[cc]=i;
			val[cc]=v[hp][i];
		}
	}
	cnt=1;
	dfs(1,hp,0);
	cout<<ans;
}
