#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c[N];
int tw[N];
struct st{
	int s,w,e,ne;
};
st bian[N];
int h[N],idx;
int p[N];
int n,m,k;
bool operator>(st a,st b){
    return a.w>b.w;
}
int bcj(int a){
	if(p[a]==a) return a;
	return p[a]=bcj(p[a]);
}
void add(int a,int b,int wt){
	bian[idx].s=a;
	bian[idx].e=b;
	bian[idx].ne=h[a];
	bian[idx].w=wt;
	h[a]=idx;
	idx++;
}
int ans=0;
void func(){
	priority_queue<st,vector<st>,greater<st>> q;
	for(int i=h[1];i!=-1;i=bian[i].ne){
		q.push({bian[i]});
	}
	while(!q.empty()){
		st eg=q.top();
		q.pop();
		int x=eg.s,y=eg.e;
		if(bcj(x)==bcj(y)){
			continue;
		}
		ans+=eg.w;
		p[y]=p[x];
		for(int i=h[y];i!=-1;i=bian[i].ne){
			int z=bian[i].e;
			if(bcj(y)==bcj(z)){
				continue;
			}
			q.push(bian[i]);
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(h,-1,sizeof h);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		add(u,v,wt);
		add(v,u,wt);
	}
	for(int i=1;i<=k;i++){
	    cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>tw[j];
//			add(n+i,j,tw);
//			add(j,n+i,tw);
		}
		for(int j=1;j<n;j++){
			for(int j2=j+1;j2<=n;j2++){
				add(j,j2,tw[j]+tw[j2]);
			    add(j2,j,tw[j]+tw[j2]);
			}
		}	
	}
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	func();
	cout<<ans;
	return 0;
}
