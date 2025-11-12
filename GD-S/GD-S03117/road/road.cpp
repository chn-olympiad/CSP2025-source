#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
};
int n,m,k,p[11001],sum=0;
node G[2030002];
void Union(int x,int y){
	p[x]=y;
}
int Find(int x){
	if(p[x]==x)
		return x;
	else return p[x]=Find(p[x]); 
}
void kruskal(){
	int counter=0;
	while(counter<n-1){
		for(int i = 1;i <= m;i++){
			if(Find(G[i].u) != Find(G[i].v)){
				Union(Find(G[i].u),Find(G[i].v));
				sum+=G[i].w;
				counter++;
			}
		}
	}
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
		p[i]=i;
	for(int i = 1;i <= m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		G[i].u=a;
		G[i].v=b;
		G[i].w=c;
	}
	sort(G+1,G+m+1,cmp);
	kruskal();
	cout << sum;
	return 0; 
}
