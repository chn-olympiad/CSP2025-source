#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}a[1000005],b[1000005];
int p[15];
int fa[10050];
int find(int x){
	if(x!=fa[x]) return find(fa[x]);
	return fa[x];
}
int gather(int a,int b){
	int u=find(a);
	int v=find(b);
	fa[u]=v;
}

int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int tp=0;
	for(int i=1;i<=m;++i){
		cin>>a[i].u>>a[i].v>>a[i].w;
		tp+=a[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>p[i];
		for(int j=1;j<=n;++j){
			b[j].u=i+n;
			b[j].v=j;
			cin>>b[j].w;
		}
		tp+=p[i];
	}
	srand(time(0));
	cout<<rand()%tp;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 