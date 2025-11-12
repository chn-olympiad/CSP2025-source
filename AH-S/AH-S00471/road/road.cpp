#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w,next;
}edge[1000005<<1];
struct nde{
	int u,v,w;
}e[1000005],E[1000005];
int M;
int c[1005];
int a[15][100005];
int fa[100005];
int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(nde a,nde b){
	return a.w<b.w;
}
int head[1000005],num;
void add(int u,int v,int w){
	edge[++num].next=head[u];
	head[u]=num;
	edge[num].v=v;
	edge[num].w=w;
}
bool v[105];
long long n,m,k,ANS=LLONG_MAX;
void check(){
	for(int i=1;i<=10100;i++)fa[i]=i;
	long long cnt=0,EP=0;
	//memset(E,0,sizeof(E));
	int nd=n;
	for(int i=1;i<=k;i++){
		//cout<<v[i]<<" ";
		if(v[i]){
			nd++;
			cnt+=c[i];
			for(int j=1;j<=n;j++){
				E[++EP].u=n+i;
				E[EP].v=j;
				E[EP].w=a[i][j];
			}
		}
	}
	E[++EP].w=INT_MAX;
	sort(E+1,E+EP+1,cmp);
	int nc=1;
	int EEP=1;
	for(int i=1;i<=M;i++){
		//cout<<E[EEP].w<<" "<<e[i].w<<endl;
		while(E[EEP].w<e[i].w&&EEP<=EP){
			int fu=find(E[EEP].u),fv=find(E[EEP].v);
			if(fu==fv){
				EEP++;
				continue;
			}
			fa[fu]=fv;
			cnt+=E[EEP].w;
			//cout<<E[EEP].u<<"->"<<E[EEP].v<<" "<<cnt<<" "<<E[EEP].w<<"|"<<e[i].w<<"ASD"<<endl;
			nc++;
			if(nc==nd)break;
			EEP++;
		}
		if(nc==nd)break;
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv)continue;
		nc++;
		//cout<<e[i].u<<"->"<<e[i].v<<" "<<cnt<<" "<<e[i].w<<"ASD"<<endl;
		fa[fu]=fv;
		cnt+=e[i].w;
		if(nc==nd)break;
	}
	//cout<<cnt<<"ASDA"<<endl;
	ANS=min(ANS,cnt);
}
void dfs(int step){
	if(step==k+1){
		check();
		//cout<<"\n";
		return;
	}
	v[step]=1;
	dfs(step+1);
	v[step]=0;
	dfs(step+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	for(int i=1;i<=100000;i++)fa[i]=i;
	cin>>n>>m>>k;
	bool f1=1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	M=m;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0)f1=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			e[++m].u=n+i;
			e[m].v=j;
			e[m].w=a[i][j];
		}
	}
	if(f1){
		sort(e+1,e+m+1,cmp);
		int cnt=1;
		long long ans=0;
		for(int i=1;i<=m;i++){
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu==fv)continue;
			cnt++;
			fa[fu]=fv;
			ans+=e[i].w;
			//cout<<edge[i].w<<" "<<
			if(cnt==n+k)break;
		}
		cout<<ans;
	}
	else{
		sort(e+1,e+M+1,cmp);
		dfs(1);
		cout<<ANS;
	}
	return 0;
}
