#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000010

int n,m,k,u,v,w,ans;
int c[N],a[20][100010];
int mx0,mx1;//for subA
struct Edge{
	int u,v,w;
}E[N],e[N],g[N];
int fth[N],tot;

bool cmp(Edge x,Edge y){
	return x.w<y.w;
}

int find(int x){
	return x==fth[x]?x:fth[x]=find(fth[x]);
}

void kruscal(){
	for(int i=1;i<=m;i++){
		int p=find(E[i].u),q=find(E[i].v);
		if(p==q) continue;
		fth[p]=q; ans+=E[i].w;
		g[++tot]=E[i];
	}
}

void solve(){
	for(int s=1;s<(1<<k);s++){
		tot=n-1;//保留原本的n-1条MST边
		int res=0,cnt=n,flag=0;
		for(int i=1;i<=tot;i++){
			e[i]=g[i];
		}
		for(int i=1;i<=k;i++){//拆解状态，加新边 
			if(!((s>>(i-1))&1)) continue;
			cnt++; res+=c[i]; 
			for(int y=1;y<=n;y++){
				e[++tot]={cnt,y,a[i][y]};
			}
		}sort(e+1,e+tot+1,cmp); 
//		for(int i=1;i<=tot;i++){
//			cerr<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
//		}
		for(int i=1;i<=cnt;i++){
			fth[i]=i;
		}
		for(int i=1;i<=tot;i++){//重跑kruscal 
			int p=find(e[i].u),q=find(e[i].v);
			if(p==q) continue;
			fth[p]=q; res+=e[i].w;
		}
//		for(int i=1;i<=cnt;i++){
//			if(find(i)==i) flag++;
//		}
//		if(flag!=1) ans=min(ans,res); 
		ans=min(ans,res);
//		cerr<<res<<"\n";
//		cerr<<"\n";
	}
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fth[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		E[i]={u,v,w};
	}sort(E+1,E+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i]; mx0=max(mx0,c[i]);
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			mx1=max(mx1,a[i][j]);
		}
	}kruscal();
	if(k==0){//k=0，原本的MST就是答案 
		cout<<ans<<"\n"; return 0;
	}else if(mx1==0&&mx0==0){
		//所有c=0且a=0，则随便挑一个c可以任意行动，答案为0
		cout<<0<<"\n"; 
	}solve();
	cout<<ans<<'\n';
	return 0;
}

