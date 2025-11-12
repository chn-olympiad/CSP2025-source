#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=10000010;
LL n,m,k,ans=LONG_LONG_MAX;
struct Node{
	int a,b,c;
	int s;
}edge[N];
int pay[N],fa[N],fg[110]; 
bool cmp(Node a,Node b){
	return a.c<b.c;
}
int find(int x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
LL kruskal(){
	LL sum=0;
	for(int i=1;i<=k;i++) if(fg[i]) sum+=pay[i];
	for(int i=1;i<=m+k*n;i++){
		if(fg[edge[i].s]==0) continue;
		int x=edge[i].a,y=edge[i].b;
		x=find(x),y=find(y);
		if(x!=y){
			fa[x]=y;
			sum+=edge[i].c;
		}
	}
	return sum;
}
void dfs(int t,int la){
	if(t==k) return;
	for(int i=la;i<=k;i++){
		if(fg[i]==0){
			fg[i]=1;
			for(int i=1;i<=n+k;i++) fa[i]=i;
			ans=min(ans,kruskal());
			dfs(t+1,i);
			fg[i]=0;
		}
	}
}
int read(){
	char x=getchar();
	while(x<'0' || x>'9') x=getchar();
	int p=x-'0';
	x=getchar();
	while(x>='0' && x<='9'){
		p=(p<<3)+(p<<1)+x-'0';
		x=getchar();
	}
	return p;
}
int main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int a,b,c;
		a=read(),b=read(),c=read();
		edge[i]={a,b,c,0};
	}
	for(int i=1;i<=k;i++){
		cin>>pay[i];
		for(int j=1;j<=n;j++){
			int t=m+(i-1)*n+j;
			int c;
			c=read();
			edge[t]={j,n+i,c,i};
		}
	}
	sort(edge+1,edge+m+k*n+1,cmp);
	fg[0]=1;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	ans=min(ans,kruskal());
	dfs(0,1);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
//4 4 1
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//0 1 8 2 4

