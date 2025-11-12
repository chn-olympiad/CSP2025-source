#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10005][10005],b[10005][10005],ans=0x3f;
bool fa[10005][10005],fb[10005],f[10005];
void dfs(int x,int cnt,int all){
	if(cnt>=ans){
		return;
	}
	cout<<x<<" "<<all<<" "<<cnt<<endl;
	if(all==n){
		ans=min(ans,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[i][x]==0x3f||fa[i][x]==true||f[i]==true){
			continue;
		}
		fa[i][x]=true;
		f[i]=true;
		dfs(i,cnt+a[i][x],all++);
		fa[i][x]=false;
		f[i]=false;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(f[i]==true){
				continue;
			}
			f[i]=true;
			int xx=b[i][x],jj=b[i][j];
			b[i][x]=0;
			b[i][j]=0;
			if(fb[i]==false){
				fb[i]=true;
				dfs(i,cnt+b[i][x]+b[i][j]+b[i][0],all++);
				fb[i]=false;
			}
			else{
				dfs(i,cnt+b[i][x]+b[i][j],all++);
			}
			b[i][x]=xx;
			b[i][j]=jj;
			f[i]=false;
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		a[x][y]=min(a[x][y],w);
		a[y][x]=min(a[y][x],w);
	}
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

