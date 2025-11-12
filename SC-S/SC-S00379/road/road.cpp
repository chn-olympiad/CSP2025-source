#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	int f=1;
	char c;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x*=f;
}
typedef pair<int,int> PII; 
const int N=1e4,M=1e6,K=10;
int n,m,k,cnt=0;
struct node{
	int to,w,next;
}edge[N*K+M+5];
int head[N+K+5];
int a[N+5];
int c[100];
bool vis[100];
int ans=0;
//bool operator < (PII a,PII b) {
//	return a.second<b.second;
//}
inline void add(int a,int b,int c){
	edge[++cnt].w=c;
	edge[cnt].to=b;
	edge[cnt].next=head[a];
	head[a]=cnt;
}
int dist[N];
void dij(){
	priority_queue<PII,vector<PII>,greater<PII>> Q;
	dist[1]=0;
	Q.push({0,1});
	while(!Q.empty()){
//		cout<<ans<<' ';
		PII x=Q.top();
		while(!Q.empty()) Q.pop();
		vis[x.second]=1;
//		cout<<x.second<<' ';
		ans+=x.first;
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
//				cout<<1<<' '<<i;
				flag=0;
				break;
			}
//			cout<<i<<' ';
		}
//		cout<<'\n';
		if(flag) return ;
		for(int i=head[x.second];i;i=edge[i].next){
//			cout<<edge[i].w<<' '<<edge[i].to<<' ';
			if(!vis[edge[i].to]){
//				cout<<edge[i].to<<' ';
				if(i>n){
//					cout<<edge[i].w+c[edge[i].to-n]<<' ';
					Q.push({edge[i].w+c[edge[i].to-n],edge[i].to});
					continue;
				}
//				cout<<edge[i].w<<' ';
				Q.push({edge[i].w,edge[i].to});
			}
		}
//		cout<<' '<<ans<<'\n';
//		putchar('\n');
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		read(u),read(v),read(w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			read(a[j]);
			add(n+i,j,a[j]);
			add(j,n+i,a[j]);
		}
	}
	dij();
//	cout<<10086;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}