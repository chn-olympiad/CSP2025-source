#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second

const int N=1e4+5,M=1e6+5;
int h[N],n,m,k,cnt,ans,c[15][N],ts[N];
bool f[N];
struct node{
	int to,nex,val;
}e[M*3];

void add(int u,int v,int d){
	e[++cnt].to=v;
	e[cnt].nex=h[u];
	e[cnt].val=d;
	h[u]=cnt;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,d;i<=m;i++){
		scanf("%d%d%d",&u,&v,&d);
		add(u,v,d);
		add(v,u,d);
	}
	bool fa=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
			if(!fa&&j==0&&c[i][j]!=0) fa=1; 
			if(!fa&&j!=0&&c[i][j]==0) ts[j]=i;
		}
	}
	
	if(k!=0&&!fa){
		for(int i=1;i<=n;i++){
			if(ts[i]==0) continue;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				add(j,i,c[ts[i]][j]);
				add(i,j,c[ts[i]][j]);
			}
		}
	}
	
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; 
	memset(f,0,sizeof(f));
	q.push(mp(0,1));
	int ab=1;
	while(!q.empty()){
		while(!q.empty()&&f[q.top().se]) q.pop();
		if(q.empty()) break;
		int u=q.top().se,t,v,d=q.top().fi;
		ans+=d;
		t=h[u];
		q.pop();
		f[u]=1;
		ab++;
		if(ab>10000) break;
		while(t){
			v=e[t].to;
			if(!f[v]) q.push(mp(e[t].val,v));
			t=e[t].nex;
		}
		
	}
	printf("%d\n",ans);
	
	
} 
