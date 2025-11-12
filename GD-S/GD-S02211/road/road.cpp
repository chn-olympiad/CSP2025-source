#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e4+2,maxm=1e6+2,maxk=10+2;
int n,m,k,c[maxk];
int fa[maxn+maxk];
long long ans=1e18;
struct node{
	int u,v,w;
}e[maxm],ad[maxk][maxn];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]!=x)return fa[x]=find(fa[x]);
	else return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	e[m].w=2e9+5;
	sort(e,e+m,cmp);
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>ad[i][j].w;
			ad[i][j].u=i+n+1;
			ad[i][j].v=j+1;	
		}
		ad[i][n].w=2e9+5;
		sort(ad[i],ad[i]+n,cmp);
	}
	for(int i=0;i<(1<<k);i++){
		long long now=0;int cnt=0,num=0,head[maxk],hd=0;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=0;j<k;j++){
			head[j]=0;
			if(i&(1<<j)){
				now+=c[j];
				num++;
			}
		}
		while(cnt<n+num-1){
			int mn=0;
			for(int j=0;j<k;j++){
				if(i&(1<<j)){
					while((find(ad[j][head[j]].u)==find(ad[j][head[j]].v))&&head[j]<n)head[j]++;
					if(ad[j][head[j]].w<ad[mn][head[mn]].w){
						mn=j;
					}
				}
			}
			while(find(e[hd].v)==find(e[hd].u)&&hd<m)hd++;
			if(ad[mn][head[mn]].w<e[hd].w&&(i&(1<<mn))){
				now+=ad[mn][head[mn]].w;
				fa[find(ad[mn][head[mn]].u)]=find(ad[mn][head[mn]].v);
			}else{
				now+=e[hd].w;
				fa[find(e[hd].u)]=find(e[hd].v);
			}
			cnt++;
		}
		ans=min(ans,now);
	}
	cout<<ans;
}
//100pts ¿ÉÄÜ¹Ò·Ö? 
