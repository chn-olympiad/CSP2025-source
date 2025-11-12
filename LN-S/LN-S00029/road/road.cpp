#include<bits/stdc++.h>
using namespace std;
const int N=10010,M=1000050;
int n,m,k,cnt,ans,t;
int p[N],build[N];
bool finish[N];
struct node{
	int a,b,w;
	bool operator<(const node &x)const{
		return w<x.w;
	}
}edges[M];
int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
void kruskal(){
	for(int i=1;i<=n+k;i++) p[i]=i;
	sort(edges+1,edges+t+1);
	for(int i=1;i<=t;i++){
		int pa=find(edges[i].a),pb=find(edges[i].b);
		if(pa!=pb){
			p[pa]=pb;
			cnt++;
			ans+=edges[i].w;
			if(!finish[edges[i].a]){
				ans+=build[edges[i].a];
				finish[edges[i].a]=true;
			}
			if(!finish[edges[i].b]){
				ans+=build[edges[i].b];
				finish[edges[i].b]=true;
			}
			//cout<<ans<<" "<<edges[i].a<<" "<<edges[i].b<<endl;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool flag=true;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edges[i].a>>edges[i].b>>edges[i].w;
		build[i]=0;
		if(edges[i].w!=0) flag=false;
	}
	t=m+1;
	for(int i=1;i<=k;i++){
		cin>>build[n+i];
		if(build[n+i]!=0) flag=false;
		for(int j=1;j<=n;j++){
			edges[t].a=n+i;
			edges[t].b=j;
			cin>>edges[t].w;
			t++;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	kruskal();
	cout<<ans;
	//for(int i=1;i<=t;i++) cout<<edges[i].a<<" "<<edges[i].b<<" "<<edges[i].w<<endl;
	return 0;
}
