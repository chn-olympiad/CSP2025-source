#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,s[N];
int a[15][N],c[15];
//int uu[N],vv[N],ww[N];
bool r[N];
struct node{
	int to,w;
};
struct st{
	int u,v,w;
	bool operator<(const st&n)const{
		return n.w>w;
	}
};
priority_queue<st,vector<st> > pq;

int _find(int x){
	if(s[x]!=x){
		s[x]=_find(s[x]);
	}
	return s[x];
}

void init(){
	for(int i=0;i<N;i++){
		s[i]=i;
	}
}

long long pp(){
	long long Min=1e9+10,mm=0,ans=0;
	while(!pq.empty()){
		st tot=pq.top();
		int u=tot.u,v=tot.v,w=tot.w;
		pq.pop();
		if(_find(s[u])!=_find(s[v])){
			Min=w,mm=0;
			for(int i=1;i<=k;i++){
				if(c[i]+a[i][u]+a[i][v]<=Min){
					Min=c[i]+a[i][u]+a[i][v];
					mm=i;
//					cout<<i<<" "<<u<<' '<<v<<endl;
				}
			}
			s[u]=s[v];
			if(mm==0){
				ans+=w;
			}else{
				ans+=Min;
				c[mm]=0,a[mm][u]=a[mm][v]=0;
			}
		}
	}
	return ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	init();
	
	cin>>n>>m>>k;
	vector<vector<node> > p(m+1);
	vector<vector<int> > e(n+1,vector<int>(n+1,INT_MAX));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		pq.push({u,v,w});
//		uu[i]=u,vv[i]=v,ww[i]=w;
		e[u][v]=w,e[v][u]=w;
		p[u].push_back({v,w});
		p[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
//	if(k==0){
//		cout<<pp()<<endl;
//		return 0;
//	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			int Min=e[i][j],mm=0;
//			for(int g=1;g<=k;g++){
//				if(c[g]+a[g][i]+a[g][j]<=Min){
//					Min=c[g]+a[g][i]+a[g][j];
//					mm=i;
//				}
//			}
//			if(mm>0){
//				e[i][j]=Min;
//				c[mm]=0,a[mm][i]=0,a[mm][j]=0;
//			}
//		}
//	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<e[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	
	cout<<pp()<<endl;
	
	return 0;
} 
