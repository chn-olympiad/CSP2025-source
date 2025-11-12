#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10005],u,v,w,p[10005];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		fa[x]=y;
	}
}
bool in(int x,int y){
	x=find(x),y=find(y);
	return x==y;
}
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    init();
    for(int i=1;i<=m;i++){
    	cin>>u>>v>>w;
    	q.push({w,u,v});
	}
	if(k==0){
		int x=0,ans=0;
		while(q.size()){
			auto i=q.top();
			q.pop();
			w=i[0],u=i[1],v=i[2];
			if(in(u,v))continue;
			ans+=w;
			x++;
			merge(u,v);
			if(x==n-1){
				cout<<ans;
				return 0; 
			}
		}
	}
	cout<<0;
    return 0;
}
