#include<bits/stdc++.h>
using namespace std;
const int N=10005;
const int M=1000025;
int n,m,k,jiage;
int fa[N];
long long ans;
struct node{
	int from;
	int to;
	int w;
}bian[10*N+M];
int find(int x){
	if(x!=fa[x])find(fa[x]);
	return x;
}
void merge(int x,int y){
	int pa=find(x),pb=find(y);
	pb=fa[x];
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>bian[i].from>>bian[i].to>>bian[i].w;
	}
	int idx=m+1;
	for(int i=1;i<=k;i++){
		int a,b;
		cin>>a;
		bian[idx].from=n+i;
		for(int j=1;j<=n;j++){
			cin>>b;
			bian[idx].to=j;
			bian[idx].w=b;
			idx++;
		}
	}
	sort(bian+1,bian+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=bian[i].from,y=bian[i].to;
		int px=find(x),py=find(y);
		if(px!=py){
			merge(x,y);
			ans+=bian[i].w;
		}
	}
	cout<<ans;
	return 0;
}
