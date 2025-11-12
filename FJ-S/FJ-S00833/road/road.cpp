#include<bits/stdc++.h>
using namespace std;

int n,m,c,k,cnt=0,W=0;
int CNT=0;
int p[10005];

struct st{
	int u,v,w;
}F[10005];

int Find(int x){
	if(p[x]==x){
		return x;
	}else{
		p[x]=Find(p[x]);
		return p[x];
	}
}

bool Jia(int u,int v){
	int x=Find(u);
	int y=Find(v);
	if(x==y)return 0;
	p[x]=y;
	return 1;
}

bool cmp(st a,st b){
	return a.w<b.w;
}

bool chesk(){
	int tt=Find(1);
	for(int i=2;i<=n;i++){
		if(Find(i)!=tt){
			return 0;
		}
	}
	return 1;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	for(int i=0;i<m;i++){
		int u,v,w; 
		cin>>u>>v>>w;
		F[CNT].u=u;
		F[CNT].v=v;
		F[CNT].w=w;
		CNT++;
	}
	for(int i=n+1;i<=k+n;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int t;
			cin>>t;
			F[CNT].u=i;
			F[CNT].v=j;
			F[CNT].w=t+c;
			CNT++;
		}
	}
	sort(F,F+CNT,cmp);
	for(int i=0;i<CNT;i++){
		cout<<F[i].u<<"-"<<F[i].v<<"-"<<F[i].w<<endl;
	}
	for(int i=0;i<CNT;i++){
		if(Jia(F[i].u,F[i].v)){
			W+=F[i].w;
		}
		if(chesk()){
			break;
		}
	}
	cout<<W<<endl;
	return 0;
}
/*
4 4 0
1 3 4
1 4 1
2 4 3
3 4 2

*/
