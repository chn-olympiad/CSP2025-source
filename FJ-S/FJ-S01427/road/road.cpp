#include<bits/stdc++.h>
using namespace std;
struct edge{
	int fr,to,w; 
}ed[20000005];
bool cmp(edge a,edge b){
	return a.w<b.w; 
}
int n,m,k,cnt=0;

int fa[10005];


void init(){
	for(int i=0;i<=n;i++) fa[i]=i;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void query(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fy]=fx;
}
long long solve(){
	long long ans=0;
	sort(ed+1,ed+m+cnt,cmp);
	for(int i=1;i<=m+cnt-1;i++){
		//cout<<ed[i].fr<<" "<<ed[i].to<<" "<<ed[i].w<<endl;
		if(find(fa[ed[i].fr])!=find(fa[ed[i].to])){
			query(ed[i].fr,ed[i].to);
			ans+=ed[i].w;
			//cout<<i<<endl;
		}
	}
	return ans;	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++){
		cin>>ed[i].fr>>ed[i].to>>ed[i].w;
	}
	int ka[10005],fro=0,fww;
	cnt=m+1;
	for(int i=1;i<=k;i++){
		cin>>fww;
		for(int j=1;j<=n;j++){
			cin>>ka[j];
			if(ka[j]==0) fro=j;
		}
		for(int j=1;j<=n;j++){
			if(fro!=j){
				ed[cnt].fr=fro;
				ed[cnt].to=j;
				ed[cnt].w=ka[j];
				cnt++;
			}
		}
	}
	cout<<solve(); 
	return 0;
}
