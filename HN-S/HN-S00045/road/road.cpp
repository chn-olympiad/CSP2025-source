//#include<bits/stdc++.h>
//using namespace std;
//#define N 11000
//#define i64 long long
//inline void read(int& x){
//	x=0;
//	char ch=getchar();
//	int f=1;
//	while(!isdigit(ch)){
//		if(ch=='-')f=~f+1;
//		ch=getchar();
//	}
//	while(isdigit(ch)){
//		x=(x<<1)+(x<<3)+(ch^48);
//		ch=getchar();
//	}
//	x=f*x;
//}
//int n,m,K;
//int build[15];
//int cost[15][N],rk[N];
//struct node{
//	int u,v,w;
//}a[1100100];
//vector<node> G[N],G1[N];
//void add(int u,int v,int w){
//	G[u].push_back({u,v,w});
//}
//void add1(int u,int v,int w){
//	G1[u].push_back({u,v,w});
//}
//int fa[N];
//int vis[1020][1030],used[1030][1030];
//i64 ans=0;
//int minn=1e9;
//bool cmp(node x,node y){
//	return x.w<y.w;
//}
//int find(int x){
//	if(fa[x]==x) return x;
//	else return fa[x]=find(fa[x]);
//}
//inline int min(int x,int y){
//	return x<y?x:y;
//}
//int edgecnt;
//void krush(){
//	int i,j;
//	sort(a+1,a+1+edgecnt,cmp);
//	int cnt=0;
//	for(i=1;i<=edgecnt;++i){
//		int u=a[i].u,v=a[i].v,w=a[i].w;
//		if(u<=K)cost[u][v]=min(a[i].w,cost[u][v]);
//		if(v<=K) cost[v][u]=min(a[i].w,cost[v][u]);
//		int ru=find(u),rv=find(v);
//		if(ru==rv) continue;
//		add(u,v,w);
//		add(v,u,w);
//		fa[rv]=ru;
//		cnt++;
//		ans+=a[i].w;
//		if(cnt==n-1)return ;
//	}
//}
//int maxx,posu,posv;
//int dfs(int u,int fath,int addr){
//	cout<<u<<" "<<fath<<endl;
//	if(u==addr) return 1;
//	int f=0;
//	for(node now:G1[u]){
//		int v=now.v,w=now.w;
//		if(v==fath) continue;
//		if(dfs(v,u,addr)){
//			f=1;
//			if(w>maxx){
//				posu=u;posv=v;
//				maxx=w;
//			}
//		}
//	}
//	return f;
//}
//signed main(){
////	freopen("road3.in","r",stdin);
////	freopen("road.out","w",stdout);
//	int i,j;
//	read(n);read(m);read(K);
////	K=0;
//	for(i=1;i<=m;++i){
//		int u,v,w;
//		read(u);read(v);read(w);
////		add(u,v,w);
////		add(v,u,w);
//		a[i]={u,v,w};
////		cost[u][v]=cost[v][u]=w;
//	}
//	for(i=1;i<=n;++i) {
//		fa[i]=i;
//	}
//	edgecnt=m;
//	krush();
//	if(K==0){
//		printf("%lld",ans);
//		return 0;
//	}
//	int flag=0;
//	i64 sum=0;
//	for(i=1;i<=K;++i){
//		read(build[i+n]);
//		sum+=build[i+n];
//		for(j=1;j<=n;++j){
//			int x;
//			read(x);
//			add(j,n+i,x+build[i+n]);
//			cost[i+n][j]=x;
//		}
//	}
//	for(i=1;i<=K;++i){
//		minn=1e9;
//		for(j=1;j<=n+i-1;++j){
//			G1[j]=G[j];
//		}
//		for(j=1;j<=K;++j){
//			for(int k=1;k<=n;++k) vis[i+n][j]=used[i+n][j];
//		}
//		i64 res=ans+sum;
//		add1(n+i,1,cost[n+i][1]);
//		add1(1,n+i,cost[n+i][1]);
//		vis[n+i][1]=1;
//		for(j=2;j<=n;++j){
//			posu=0;
//			maxx=cost[n+i][j];
//			dfs(n+i,0,j);
////			puts("ok");
//			cout<<posu<<" "<<posv<<endl;
//			if(posu==0) continue;
//			vis[max(posu,posv)][min(posv,posu)]=0;
//			for(int k=0;k<G1[posu].size();k++){
//				if(G1[posu][k].v==posv){
//					G1[posu].erase(k+G1[posu].begin());
//					break;
//				}
//			}
//			for(int k=0;k<G1[posv].size();k++){
//				if(G1[posv][k].v==posu){
//					G1[posu].erase(k+G1[posv].begin());
//					break;
//				}
//			}
//			res-=maxx;
//			res+=cost[n+i][j];
//			add(n+i,j,cost[n+i][j]);
//			add(j,n+i,cost[n+i][j]);
//		}
//		for(j=1;j<=K;j++){
//			int num=0;
//			for(int k=1;k<=n;++k){
//				if(vis[j][k]==1) num++;
//			}
//			if(num<=1) res-=build[j+n];
//		}
//		if(res<ans){
//			ans=res;
//			for(j=1;j<=n+i-1;++j){
//				G[j]=G1[j];
//			}
//			for(j=1;j<=K;++j){
//				for(int k=1;k<=n;++k) used[i+n][j]=vis[i+n][j];
//			}
//		}
//	}
////	cout<<cost[1][2]<<endl;
//	printf("%lld\n",ans);
//	return 0;
//}
///*
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
//
//*/
#include<bits/stdc++.h>
using namespace std;
#define N 20020
#define i64 long long
inline void read(int& x){
	x=0;
	char ch=getchar();
	int f=1;
	while(!isdigit(ch)){
		if(ch=='-')f=~f+1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x=f*x;
}
int n,m,K;
int build[15];
int cost[15][N],rk[N];
struct node{
	int u,v,w,nxt;
}a[2100100],edge[2000100];
int head[N],tot;
void add(int u,int v,int w){
	edge[++tot]={u,v,w,head[u]};
	head[u]=tot;
}
int fa[N];
i64 ans=0;
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
inline int min(int x,int y){
	return x<y?x:y;
}
int edgecnt;
void krush(){
	int i,j;
	sort(a+1,a+1+edgecnt,cmp);
	int cnt=0;
	for(i=1;i<=edgecnt;++i){
		int u=a[i].u,v=a[i].v,w=edge[i].w;
		if(u<=K)cost[u][v]=min(a[i].w,cost[u][v]);
		if(v<=K) cost[v][u]=min(a[i].w,cost[v][u]);
		int ru=find(u),rv=find(v);
		if(ru==rv) continue;
		add(u,v,w);
		add(v,u,w);
		fa[rv]=ru;
		cnt++;
		ans+=a[i].w;
		if(cnt==n-1+K)return ;
	}
}
//unordered_map<int,int> used[N];
int used[N];
struct point{
	int u;
	i64 sum;
	int vis,num1,num2;
//	point(){
//		u=0;sum=0;
//		for(int i=1;i<=K;i++) vis[i]=0;
//	}
	bool operator <(const point& X)const{
		return sum>X.sum;
	}
};
priority_queue<point> q;
void Prim(){
	int i,j;
	point st;
	st.u=1;st.sum=0;st.vis=0;st.num1=1;st.num2=0;
	q.push(st);
	int cnt=0;
	while(!q.empty()){
		point now=q.top();q.pop();
//		if(used[now.u]) continue;
		used[now.u]=1;
		if(now.num1==n+now.num2){
			ans=now.sum;
			break;
		}
//		cout<<now.u<<" "<<now.sum<<" "<<now.vis<<" "<<now.num1<<" "<<now.num2<<endl;
		int u=now.u;
		if(now.vis){
			for(int v=1;v<=n;++v){
				point temp;
				if(!used[v]){
					temp=now;
					if(temp.sum+cost[u][v]<ans){
						temp.num1++;
						temp.u=v;
						temp.sum+=cost[u][v];
						temp.vis=0;
//					cout<<u<<"/"<<v<<"/"<<temp.sum<<endl;
						q.push(temp);
					} 
				}
			}
		}else{
			
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].v,w=edge[i].w;
				point temp;
				if(!used[v]){
					temp=now;
					if(temp.sum+w<ans){
						temp.num1++;
						temp.num2+=(v>n);
						temp.u=v;
						temp.sum+=w;
						temp.vis=(v>n);
//					cout<<u<<"/"<<v<<"/"<<temp.sum<<endl;
						q.push(temp);
					}
				}
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	read(n);read(m);read(K);
//	K=0;
	for(i=1;i<=m;++i){
		int u,v,w;
		read(u);read(v);read(w);
//		add(u,v,w);
//		add(v,u,w);
		a[i]={u,v,w};
//		cost[u][v]=cost[v][u]=w;
	}
	for(i=1;i<=n+K;++i) {
		fa[i]=i;
//		for(j=1;j<=K;++j)cost[j+n][i]=1e9;
	}
	edgecnt=m;
	int flag=0;
	for(i=1;i<=K;++i){
		read(build[i+n]);
		if(build[i+n]==0){
			flag++;
		}
		for(j=1;j<=n;++j){
			int x;
			read(x);
			cost[i][j]=x;
		}
	}
//	puts("ok");
	if(flag==K){
//		puts("ok");
		for(i=1;i<=K;++i){
			for(j=1;j<=n;++j){
				a[++edgecnt]={n+i,j,cost[i][j]};
			}
		}
//		cout<<edgecnt;
		krush();
		for(i=1;i<=K;i++){
			int kids=0,w=0;
			for(j=head[i+n];j;j=edge[j].nxt){
				int v=edge[j].v;
				w=edge[j].w;
				kids++;
			}
			if(kids==1) ans-=w;
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(K==0){
//		puts("ok");
		printf("%lld\n",ans);
		return 0;
	}
//	cout<<cost[1][2]<<endl;
//	if(K!=0)Prim();
//	printf("%lld\n",ans);
//puts("no");
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

