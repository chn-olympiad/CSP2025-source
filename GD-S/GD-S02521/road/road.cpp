#include<bits/stdc++.h>
using namespace std;
struct nd{
	int from,to,cost;
};
vector<int> par;
vector<int> siz;
int n,m,k;
int F(int a){
	if(par[a]==a)	return a;
	par[a]=F(par[a]);
	siz[a]=siz[par[a]];
	return par[a];
}
void U(int a,int b){
	int fa=F(a),fb=F(b);
	if(fa==fb)	return;
	par[fa]=fb;
	siz[fb]+=siz[fa];
}
bool check(){
	int p=par[1];
	for(int i=2;i<=n;i++){
		if(p!=par[i])	return false;
	}
	return true;
}
bool cmp(nd A,nd B){
	return A.cost<B.cost;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	vector<nd> rds(m);
	par=vector<int>(n+1);
	siz=vector<int>(n+1,1);
	for(int i=1;i<=n;i++)	par[i]=i; 
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&rds[i].from,&rds[i].to,&rds[i].cost);
	}
	vector< vector<int> > vall(k,vector<int>(n+1));
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&vall[i][j]);
		}
	}
	sort(rds.begin(),rds.end(),cmp);
	long long ans=0;
	for(auto rd:rds){
		if(F(rd.from)==F(rd.to))	continue;
		ans+=rd.cost;
		U(rd.from,rd.to);
		if(siz[1]==n)	break;
	}
	printf("%lld",ans);
	return 0;
}
