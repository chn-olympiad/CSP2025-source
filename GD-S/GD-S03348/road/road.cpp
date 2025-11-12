#include<bits/stdc++.h>
using namespace std;
const int N=1e4+40;
#define ll long long
#define pii pair<int,int> 
#define fir first
#define sec second
#define mkpir make_pair

//void opened(){
//}

inline int read(){
	int w=1,f=0;
	char c=getchar();
	while(c<'0'&&c>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	
	while(c>='0'&&c<='9'){
		f=10*f+c-'0';
		c=getchar();
	}
	return f*w;
	
}

int n,m,k;
int c[N];
int g[20][N];
int root[N];

int cnt=n+k;
ll ans=0;

void init(){
	for(int i=1;i<=n+k;i++){
		root[i]=i;
	}
}
inline int find(int x){
	if(x==root[x])return x;
	return root[x]=find(root[x]);
} 
bool Union(int x,int y){
	int rootx=find(x),rooty=find(y);
	if(rootx!=rooty){
		root[rooty]=rootx;
		cnt--;
		return true;
	}
	return false;
}


struct edge{
	int u,v,w;
}; 
edge mke(int u,int v,int w){
	return edge{u,v,w};
}
struct cmp{
	bool operator()(edge A,edge B){
		return A.w>B.w;
	}
};



priority_queue<edge,vector<edge>,cmp> pq;

int main(){
//	opened();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	
	n=read(),m=read(),k=read();
	int u,v,w;
	
	init();
	
	for(int rp=1;rp<=m;rp++){
		u=read();
		v=read();
		w=read();
		
		pq.push(mke(u,v,w));
//		cout<<"u="<<u<<" v="<<v<<" w="<<w<<endl;
	}
	
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			g[i][j]=read();
			pq.push(mke(n+i,j,g[i][j]));
		}
	}
	
	cnt=n+k;
	
	while(cnt>1&&!pq.empty()){
		edge p=pq.top();pq.pop();
//		cout<<p.u<<" "<<p.v<<" "<<p.w<<endl;
		if(Union(p.u,p.v)){
			ans+=p.w;
		}
	}
	
	cout<<ans;
	
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 1 1 1
0 1 0 1 1

*/
