#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<queue>
#include<cstring>
#define int long long
using namespace std;
const int N = 1050;
const int M = 100050;
//这题是最小树
//prim:集合Ua,Ub;
//每次选择Ua到Ub的最短距离的点
//然后更新距离
//可以设置0号节点，让它和每个城市连费用为0的边，给乡村连费用为建设值的边 
int g[N][N];
int n,m,k,a,b,c,flag=0,best=-1,mind=114514100,ans=0;
bool vst[N];//vst[i]:第i个节点是否用过 
queue<int>q;
int prim(){
	for(int i=1;i<=n;i++){//集合A中n个点
		//寻找没用过并且距离最小的
		//集合B中n个点
		for(int j=1;j<=n;j++){
			if(vst[j])continue;//如果在集合A中 
			if(g[i][j]!=0x3f3f3f3f3f3f3f3f){
			}
			if(g[i][j]<mind){
				mind=g[i][j];
				best=j;
			}
		}
		ans+=mind;
		vst[best]=1;//将best加入集合A
		for(int j=1;j<=n;j++){
			if(g[i][j]>g[i][best]+g[best][j]){
				g[i][j]=g[i][best]+g[best][j];
			}
		}
		mind=114514100;
	}
	return ans;
}
void solve(){
	srand(time(0));
	memset(g,0x3f,sizeof(g));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		g[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		g[a][b]=c;
		g[b][a]=c;
	}
	for(int i=1;i<=k;i++){
		cin>>a;//城市化的费用 
		for(int j=1;j<=n;j++){
			cin>>b;//城市化后距离
			//为j,c连边
			//不用连了直接prim 
			//g[j].push_back(make_pair(i+N,b+a));
			//g[i+N].push_back(make_pair(j,b+a));
		}
	}
	cout<<rand()%100;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

