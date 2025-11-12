#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=1e4+10,M=1e6+10;
int n,m,K;
struct node{
	int u,v,w;
}e[M],E[M];
int tot,Tot;
int c[15][N];
int fa[N];
int vis[15],pred[15];
queue<int> q,Q1,Q2;
ll ans,sum;

bool cmp(node u,node v){
	return u.w<v.w;
}

int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>K;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[++tot]={u,v,w};
	}
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=K;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=tot;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fx=find(u),fy=find(v);
		if(fx==fy)continue;
		q.push(i);
		fa[fx]=fy;
		ans+=w;
	}
	for(int k=1;k<=K;k++){
		int mercnt=0;
		ll Ans=0;
		for(int i=1;i<=10;i++)vis[i]=pred[i]=0;
		while(q.size()){
			Q1.push(q.front()),Q2.push(q.front());
			q.pop();
		}
		while(Q1.size()){
			E[++Tot]=e[Q1.front()];
			Q1.pop();
		}
		for(int j=1;j<=n;j++){
			E[++Tot]={n+k,j,c[k][j]};
		}
		sort(E+1,E+1+Tot,cmp);
		for(int i=1;i<=n+10;i++)fa[i]=i;
		for(int i=1;i<=Tot;i++){
			int u=E[i].u,v=E[i].v,w=E[i].w;
			int fx=find(u),fy=find(v);
			if(fx==fy)continue;
			if(u<=n&&v<=n)mercnt++;
			if(mercnt==n-1)break;
			if(u>n){
				if(vis[u-n]==0)pred[u-n]=w;
				vis[u-n]++;
			}
			Q1.push(i);
			fa[fy]=fx;
			Ans+=w;
		}
		bool flag=false;
		sum=0;
		for(int i=1;i<=k;i++){
			if(vis[i]==1)Ans-=pred[i];
			if(vis[i]>1)sum+=c[i][0];
		}
		if(Ans+sum<ans){
			for(int i=1;i<=Tot;i++)e[i]=E[i];
			ans=Ans+sum;
			flag=true;
		}
		if(flag){
			while(Q1.size()){
				q.push(Q1.front());
				Q1.pop();
			}
			while(Q2.size())Q2.pop();
		}
		else{
			while(Q2.size()){
				q.push(Q2.front());
				Q2.pop();
			}
			while(Q1.size())Q1.pop();
		}
		Tot=0;
	}
	cout<<ans; 
	return 0;
}
