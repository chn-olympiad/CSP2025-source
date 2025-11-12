#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ff[1100010];
int sumc,tot;
int cost_bulid[11],c[11][1100010];
struct node{
	int u,v,va,id;
}E[1100010];
bool cmp(node x,node y){return x.va<y.va;}
bool cmp2(node x,node y){return x.id<y.id;}
int getfa(int x){return ((x^ff[x]?getfa(ff[x]):x));}
void kruskal(int addn,int addm){
	sumc=0;
	for(int i=1;i<=m+addm;i++){
		int f1=getfa(E[i].u),f2=getfa(E[i].v);
		if(f1!=f2){
			sumc+=E[i].va;
			ff[f1]=f2;
			tot++;
		}
		if(tot==n+addn-1) break;
	}
}
void sp_A(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			E[++m].u=n+i;E[m].v=j;E[m].va=c[i][j];
		}
	}
	n+=k;
	sort(E+1,E+m+1,cmp);
	kruskal(0,0);
	cout<<sumc;
}
int work(int x){
	int sd=m,now=1,deta=0;
	while(x){
		if(x&1){
			deta++;
			for(int j=1;j<=n;j++){E[++sd].u=n+now;E[sd].v=j;E[sd].va=c[now][j];E[sd].id=sd;}
		}
		x>>=1;now++;
	}
	sort(E+1,E+sd+1,cmp);
	kruskal(sd-m,deta);
	int sumc1=sumc;
	sort(E+1,E+sd+1,cmp2);
	return sumc1;
}
void sp_B(){
	int final_ans=sumc;
	for(int i=1;i<=(1<<(k+1))-1;i++) final_ans=min(final_ans,work(i));
	cout<<final_ans;
}
int main(){
	freopen("road1.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>E[i].u>>E[i].v>>E[i].va,E[i].id=i;
	bool check=1;
	for(int i=1;i<=k;i++){
		cin>>cost_bulid[i];
		if(cost_bulid[i]!=0) check=0;
		for(int j=1;j<=n;j++) cin>>c[i][j];
	}
	for(int i=1;i<=n+k;i++) ff[i]=i;
	if(check){sp_A();return 0;}
	sort(E+1,E+m+1,cmp);
	if(k<=5){sp_B();return 0;}
	kruskal(0,0);
	cout<<sumc;
	return 0;
}
