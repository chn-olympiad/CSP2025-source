#include<bits/stdc++.h>
using namespace std;
const int N=11451,M=1e7;
struct sj{
	long long u,v,w;
}e[M];
long long c[14][N];
int f[N],vst[N];
long long ans=0,sum=0,maxm,n,m,k,cnt=0;
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
bool check(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx==yy) return 0;
	f[yy]=xx;
	return 1;
}
void krusk(){
	int cntt=0;
	for(int i=1;i<=m;i++){
		if(check(e[i].u,e[i].v)){
			//cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
			ans+=e[i].w;
			cntt++;
			if(cntt==n-1) break;
		}
	}
}
bool cmp(sj x,sj y){
	return x.w<y.w;
} 
void dfs(int step,int pos){
	if(step==0) return;
	for(int i=pos;i<=k;i++){
		if(vst[i]==0){
			vst[i]=1;
			long long maxn=0,tpmaxm=maxm,tpsum=sum;
			sum+=c[i][0];
			for(int ii=1;ii<=n;ii++){
				for(int j=i+1;j<=n;j++){
					e[++maxm]={ii,j,c[i][ii]+c[i][j]};
				}
			}
			stable_sort(e+1,e+1+maxm,cmp);
			for(int i=1;i<=n;i++) f[i]=i; 
			for(int i=1;i<=maxm;i++){
				if(check(e[i].u,e[i].v)){
					sum+=e[i].w;
					maxn++;
					if(maxn==n-1) break;
					if(sum>ans) break;
				}
			}
			ans=min(ans,sum);
			dfs(step-1,i);
			maxm=tpmaxm;
			sum=tpsum;
			vst[i]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	bool bf=1;
	maxm=m;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		if(c[i][0]!=0) bf=0;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	if(bf==1 or k==0){
		for(int ii=1;ii<=k;ii++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					e[++m]={i,j,c[ii][i]+c[ii][j]};
				}
			}
		}
		sort(e+1,e+1+m,cmp);
		krusk();
		cout<<ans;
		return 0;
	}
	else{
		sort(e+1,e+1+m,cmp);
		krusk();
		cnt=0;
		dfs(k,1);
		cout<<ans;
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
图论....已经如呼吸般简单了 
*/
