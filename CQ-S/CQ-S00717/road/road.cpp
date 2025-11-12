#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
int len=0;
int kans=0;
int ans=0;
int con[1000000];
map<int,int>mp;
//vector<pair<int,int>>ed[100000];
int c[1000000];
struct node{
	int u,v,w;
}e[10000000];
bool cmp(node aa,node bb){
	return aa.w<bb.w;
}
int fa[10000000];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
}
void ksc(){
	sort(e+1,e+1+len,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt==n){
			break;
		}
		if(find(e[i].u)!=find(e[i].v)){
			if(e[i].u<=n&&mp[e[i].u]==1){
				cnt+=1;
				mp[e[i].u]=0;
			}
			if(e[i].v<=n&&mp[e[i].v]==1){
				cnt+=1;
				mp[e[i].v]=0;
			}
			kans+=e[i].w;
			cnt+=1;
			merge(e[i].u,e[i].v);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		mp[i]=1;
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		len+=1;
		e[len].u=u;
		e[len].v=v;
		e[len].w=w;
	}
	if(k==0){
		ksc();
		cout<<kans;
		return 0;
	}
	int f=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			f=0;
		}
		for(int i=1;i<=n;i++){
			cin>>con[i];
		}
	}
	if(f){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				len+=1;
				e[len].u=n+i;
				e[len].v=j;
				e[len].w=con[j];
			}
		}
		
	}
	ksc();
	cout<<kans;
	return 0;
} 
