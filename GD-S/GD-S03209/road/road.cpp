#include<bits/stdc++.h>
using namespace std;
int n,m,k,jsq=1,nc[15],fa;
struct fy{
	int t,v,w;
};
bool lt[10055]={false};
vector<fy> edge;
bool cmp (fy a,fy b){
	return a.w<b.w;
}
void kluskarl(int s){
	sort(edge,edge+m+k*n,cmp);
	lt[s]=true;
	while(jsq<n){
		for(int i=0;i<edge.size();i++){
			if(!lt[edge[i].v]&&lt[edge[i].t]){
				lt[edge[i].v]=true;
	 			ans+=edge[i].w;
	 			if(edge[i].v<=n)jsq++;
			}
		}
	}
	return ;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int tt,mdi,pa;
		cin>>tt>>mdi>>pa;
		fy q;
		q.t=tt,q.v=mdi,q.w=pa;
		edge.push_back(q);
		q.t=mdi,q.v=tt;
		edge.push_back(q);
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		nc[i]=c;
		for(int j=1;j<=n;j++){
		int pa;
		cin>>pa;
		fy q;
		q.t=i,q.v=j+n,q.w=pa;
		edge.push_back(q);
		q.t=j+n,q.v=i;
		edge.push_back(q);
		}
	}
	kluskarl(1);
	cout<<ans;
}
