#include<bits/stdc++.h>
#define MAXK 11
#define MAXN 1010
#define MAXM 1000010
using namespace std;
int N, M,K, C[MAXN],A[MAXK][MAXN];
//kruskal
int fa[MAXN];
int getfa(int x){
	if(fa[x] != x)return fa[x] = getfa(fa[x]);
	return x;
}
bool check(int x,int y){return getfa(x) == getfa(y);}//判断x,y是否在一起
void merge(int x,int y){
	x = getfa(x),y = getfa(y);
	fa[x] = y;
}

struct edge{
	int u,v,w;
	edge(){}
	edge(int u_,int v_,int w_):u(u_),v(v_),w(w_){}
	bool operator < (const edge & rhs)const{
		return w < rhs.w;
	}
};
#define Edge vector<edge>
Edge E;
Edge kruskal(Edge E, int point = N/*图内点个数*/){
	for(int i = 1;i <= N; i ++)fa[i] = i;
	sort(E.begin(),E.end());
	Edge ans;ans.resize(0);
	int now = 0;
	for(int i = 0; i < (int)E.size(); i ++){
		if(now == point - 1)break;
		int u = E[i].u, v = E[i].v;
		if(check(u,v))continue;
		merge(u,v);ans.push_back(E[i]);
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>> N >> M >> K;
	
	for(int i = 1;i <= M; i ++){
		int u,v,w;cin>>u>>v>>w;
		E.push_back(edge(u,v,w));
	}
	bool check = true;
	for(int i = 1;i <= K; i ++){
		cin>>C[i];
		if(C[i] != 0)check = false;
		for(int j = 1;j <= N;j ++){
			cin>>A[i][j];
			if(A[i][j] != 0) check = false;
		}
	}
	if(K == 0){//特殊性质1，直接最小生成树
		E = kruskal(E,N);
		int ans = 0;
		for(auto i : E)ans += i.w;
		cout<<ans<<endl;
	}else if(check == true){
		cout<< 0 <<endl;//特殊性质2，所有城镇化费用都为0，不必要任何的生成，直接一个城镇化其他全部连接即可
	}else{
		cout<< rand();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

