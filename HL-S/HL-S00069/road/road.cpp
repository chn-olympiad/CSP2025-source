#include<bits/stdc++.h>
#define re register 
using namespace std;
struct Node{
	int u,v,w;
};
int n,m,k,u,v2,w2;
vector<Node> v;
inline bool cmp(Node x,Node y){
	return x.w<y.w;
}
int fa[1000100]={0},le[1000100]={0},w[20]={0},asd[20]={0};
inline int f(int x){
	int x2=x;
	while(x!=fa[x]) x=fa[x];
	return fa[x2]=x; 
}
inline void up2(int u,int v,int w3){
	if(u>n){w[u-n]++,asd[u-n]=w3;/*cout<<"likuh"<<u;*/} 
	if(v>n){w[v-n]++,asd[v-n]=w3;/*cout<<"ljhug"<<v;*/}
}
inline bool up(int u,int v){
	le[v]+=le[u];
	le[u]=0;
	if(le[v]>=n) return true;
	return false;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(re int i=1;i<=n;i++) fa[i]=i,le[i]=1;
    for(re int i=n;i<=n+k;i++) fa[i]=i;
    for(re int i=1;i<=m;i++){
    	cin>>u>>v2>>w2;
    	v.push_back({u,v2,w2});
    //	v.push_back({v2,u,w});
	}
	for(re int i=1;i<=k;i++){
	    cin>>u;
		for(int j=1;j<=n;j++){
			cin>>w2;
			v.push_back({i+n,j,w2});
		}	
	}
	sort(&v[0],&v[v.size()],cmp);
	int len=v.size();
	unsigned long long ans=0;
	for(re int i=0;i<len;i++){
		Node x=v[i];
        int u=x.u,v=x.v;
        int fu=f(u),fv=f(v);
        if(fu!=fv){
        	fa[fu]=fv;
        	ans+=x.w;
        	if(up(fu,fv)) break;
        	up2(u,v,x.w);
		} 
	}
	for(int i=1;i<=k;i++){
		if(w[i]==1){
		    ans-=asd[i];
		}
	}
	cout<<ans;
	return 0;
}
