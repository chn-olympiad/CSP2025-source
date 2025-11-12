#include<bits/stdc++.h>
#define N 1000005
using namespace std;
struct node{
	int u,v;
	long long w;
	int fa_u,fa_v;
}s[N],step[10005];
int g[15][10005],c[15];
int fa[N];
long long minn[N][15];
int getfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&s[i].u,&s[i].v,&s[i].w);
	sort(s+1,s+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	long long ans=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(getfa(s[i].u)!=getfa(s[i].v)){
			ans+=s[i].w;
			step[++cnt]=((node){s[i].u,s[i].v,s[i].w,getfa(s[i].u),getfa(s[i].v)});
			fa[getfa(s[i].u)]=getfa(s[i].v);
		}
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>g[i][j];
	}
	long long ANS=2e18;
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=n;j++){
			fa[j]=j;
			for(int l=1;l<=k;l++){
				if((1<<(l-1))&i)minn[j][l]=g[l][j];
			}
		}
		long long ans=0;
		for(int j=1;j<n;j++){
			int fa_u=step[j].fa_u;
			int fa_v=step[j].fa_v;
			long long tot=2e18;
			if(fa_u!=fa_v){
				for(int l=1;l<=k;l++){
					if((1<<(l-1))&i){
						tot=min(tot,minn[fa_u][l]+minn[fa_v][l]);
					}
				}
				ans+=min(step[j].w,tot);
				fa[fa_u]=fa_v;
				for(int l=1;l<=k;l++){
					if((1<<(l-1))&i){
						minn[fa_v][l]=min(minn[fa_u][l],minn[fa_v][l]);
					}
				}
			}
		}
		for(int l=1;l<=k;l++){
			if((1<<(l-1))&i)ans+=c[l];
		}
		ANS=min(ANS,ans);
		
	}
	cout<<ANS;
	fclose(stdin);
	fclose(stdout);
	return 0;
}