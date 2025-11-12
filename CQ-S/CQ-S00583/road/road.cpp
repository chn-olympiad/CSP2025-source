#include<bits/stdc++.h>
using namespace std;
#define int long long
int p[50],w[20][11000],n,m,k,fa[13000],ank;
struct pp{
	int x,y,w;
}ku[1300000];
int cmp(pp a,pp b){
	return a.w<b.w;
}
int fc(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=fc(fa[x]);
}
void dfs(int ka,int pa,int now){
	if(now>ank){
		return;
	}
	if(pa==1){
		sort(ku+1,ku+1+m,cmp);
		int ans=now;
		for(int i=1;i<=n+ka-1;i++){
			fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			if(fc(ku[i].x)!=fc(ku[i].y)){
			//	cout<<ku[i].x<<" "<<ku[i].y<<"--"<<fa[ku[i].x]<<" "<<fa[ku[i].y]<<endl;
				ans+=ku[i].w;
				if(ans>ank){
					break;
				}
				fa[fa[ku[i].x]]=fa[ku[i].y];
			}
		}
	//	cout<<ans<<" ";
		ank=min(ank,ans);
	}
	if(ka==k+1){
		return;
	}
	for(int i=1;i<=n;i++){
		m++;
		ku[m].x=i,ku[m].y=ka+n,ku[m].w=w[ka][i];
	}
	dfs(ka+1,1,now+p[ka]);
	m-=n;
	dfs(ka+1,0,now);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ank=1e13;
	for(int i=1;i<=m;i++){
		cin>>ku[i].x>>ku[i].y>>ku[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>p[i];
		for(int j=1;j<=n;j++){
			cin>>w[i][j];
		}
	}
	dfs(1,1,0);
	cout<<ank;
	return 0;
}
//T1 60(again!) T2²¢²é¼¯£¿ Ô¤¹À£º64
