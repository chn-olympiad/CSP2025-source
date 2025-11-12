#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=2e6+10;
struct node{
	int x,y,w;
}e[N];
int n,m,k,cnt,fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void unionn(int x,int y){
	x=find(x); y=find(y);
	if(x!=y){
		fa[x]=y;
	}
	return ;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int kruskal(){
	int sum=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		if(find(e[i].x)==find(e[i].y)) continue;
		sum+=e[i].w;
		cnt++;
		unionn(e[i].x,e[i].y);
		if(cnt==n-1) return sum;
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>e[i].x>>e[i].y>>e[i].w;
		}
		sort(e+1,e+1+m,cmp);
		cout<<kruskal();
	}
	return 0;
}
