#include <bits/stdc++.h>
using namespace std;
int n,m,k,b[15],t[15],d[15][10005],f[10005],z;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	f[find(x)]=find(y);
}
struct rp{
	int from,to,w;
};
operator <(rp x,rp y){
	return x.w>y.w;
}
priority_queue<rp> q;
vector<rp> v;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		while(m--){
			int u,v,w;
			cin>>u>>v>>w;
			q.push({u,v,w});
		}
		while(!q.empty()){
			if(find(q.top().from)!=find(q.top().to)){
				merge(q.top().from,q.top().to);
				z+=q.top().w;
				v.push_back(q.top());
			}
			q.pop();
		}
		cout<<z<<endl;
	}
	else{
		cout<<0<<endl;
	}
}
