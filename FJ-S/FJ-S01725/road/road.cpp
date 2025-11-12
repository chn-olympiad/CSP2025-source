#include<iostream>
#include<queue>
using namespace std;
struct edge{
	int u,v,w,nxt;
}E[3000001];
int H[200001],F[200001],d[200001],tail,Cl[200001];
int n,m,k,reans=1000000000,tot=0;
int top(){
	return d[1];
}
void add(int i){
	if(i==1) return ;
	if(i&1){
		if(E[d[(i-1)/2]].w>E[d[i]].w){
			swap(d[(i-1)/2],d[i]);
			add((i-1)/2);
		}
	}else{
		if(E[d[i/2]].w>E[d[i]].w){
			swap(d[i/2],d[i]);
			add(i/2);
		}
	}
}
void ext(int i){
	if(d[i*2]==-1&&d[i*2+1]==-1) return ;
	if(E[d[i*2]].w>E[d[i*2+1]].w||d[i*2]==-1){
		if(E[d[i*2+1]].w<E[d[i]].w){
			swap(d[i*2+1],d[i]);
			ext(i*2+1);
		}
	}else{
		if(E[d[i*2]].w<E[d[i]].w){
			swap(d[i*2],d[i]);
			ext(i*2);
		}
	}
}
int prim(){
	int sum=1,ans=0;
	for(int i=1;i<=n;i++) F[i]=0;
	for(int i=H[1];i;i=E[i].nxt){
		if(F[E[i].v]==1) continue; 
		d[++tail]=i;
		add(tail);
	}
	F[1]=1;
	while(sum<n){
		if(tail==0){
			return 1000000000;
		}
		int u=top();
		swap(d[1],d[tail]);
		d[tail--]=-1;
		ext(1);
		if(F[E[u].v]==1) continue;
		F[E[u].v]=1;
		if(E[u].v<=n)sum++;
		ans+=E[u].w;
		for(int i=H[E[u].v];i;i=E[i].nxt){
			if(F[E[i].v]==1) continue;
			d[++tail]=i;
			add(tail);
		}
	}
	while(tail>0) d[tail--]=-1;
	//cout<<'\n';
	return ans;
}
void A(int i,int sum){
	if(i>k){
		//cout<<prim<<'\n';
		reans=min(reans,prim()+sum);
		//cout<<reans<<'\n';
	}else{
		F[i+n]=1;
		A(i+1,sum);
		F[i+n]=0;
		A(i+1,sum+Cl[i]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=100000;i++) d[i]=-1;
	for(int i=1;i<=m;i++){
		cin>>E[i].u>>E[i].v>>E[i].w;
		E[i+m].u=E[i].v,E[i+m].v=E[i].u;E[i+m].w=E[i].w;
		E[i].nxt=H[E[i].u];
		H[E[i].u]=i;
		E[i+m].nxt=H[E[i+m].u];
		H[E[i+m].u]=i+m;	
	}
	int tot2=0;
	for(int i=1;i<=k;i++){
		cin>>Cl[i];
		for(int j=1;j<=n;j++){
			++tot2;
			int bi=2*m+tot2;
			E[bi].u=n+i,E[bi].v=j;
			cin>>E[bi].w;
			E[bi].nxt=H[E[bi].u];
			H[E[bi].u]=bi;
			E[bi+1].u=j,E[bi+1].v=n+i;
			E[bi+1].w=E[bi].w;
			E[bi+1].nxt=H[E[bi+1].u];
			H[E[bi+1].u]=bi+1;
			//cout<<E[bi].u<<" "<<E[bi].v<<" "<<E[bi].w<<'\n';
			tot2++;
		}
	}
	A(1,0);
	cout<<reans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
