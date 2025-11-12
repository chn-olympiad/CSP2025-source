//T1贪心，黄
//T2Kruskal+子集枚举。
//期待T3
//我爱你。

#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
inline int read(){
	char c;
	int res=0;
	c=getchar();
	while(isdigit(c)) {
		res*=10,res+=c-'0';
		c=getchar();
	}
	return res;
}
struct edge{
	int u,v,w;
};
bool cmp(edge A,edge B){
	return A.w<B.w;
}
vector<edge> v1,v2;
int c[25][N];//c[i][0]存城市化改造价格，剩余部分存连接成本 
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);//并查集 
}
void merge(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y;
}
void init(int limit){
	for(int i=1;i<=limit;i++){
		fa[i]=i;
	}
}
long long ans=0;
void kruskal(vector<edge> v,int limit){
	ans=0;
	init(limit);
	sort(v.begin(),v.end(),cmp);
	for(auto p:v){
		if(find(p.u)!=find(p.v)){
			ans+=p.w;
			merge(p.u,p.v);
		}
	}
}
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	//cin >> n >> m >> k;
	//scanf("%d%d%d",&n,&m,&k);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		//cin >> u >> v >> w;
		//scanf("%d%d%d",&u,&v,&w);
		u=read(),v=read(),w=read();
		v1.emplace_back((edge){u,v,w});
	}
	int sum=0;
	for(int i=1;i<=k;i++){
		//cin >> c[i][0];
		//scanf("%d",&c[i][0]);
		c[i][0]=read();
		sum+=c[i][0];
		for(int j=1;j<=n;j++) c[i][j]=read();//scanf("%d",&c[i][j]); //cin >> c[i][j];
	}
	if(k==0){
	    ans=0;
		kruskal(v1,n);
		printf("%lld",ans);
		//cout << ans << endl;
	}else if(!sum){
		for(auto t:v1){
			v2.emplace_back(t); 
		}
		long long S=(1<<k)-1,res=0x3f3f3f3f;
		int T=S;
		bool In[11]={0,0,0,0,0,0,0,0,0,0,0};
		for(int i=0;i<k;i++){
			if(T&(1<<i)) In[i+1]=1;
		}
			
		int cost=0;
		for(int i=1;i<=k;i++){
			if(In[i]){
				cost+=c[i][0];
				for(int j=1;j<=n;j++){
					v2.emplace_back((edge){n+i,j,c[i][j]});
				}
			}
		}
		kruskal(v2,n+k);
		v2.resize(m+1);
		res=min(res,ans+cost);
		//cout << res << endl;
		printf("%lld",res);
	}else{
		for(auto t:v1){
			v2.emplace_back(t); 
		}
		long long S=(1<<k)-1,res=0x3f3f3f3f;
		for(int T=0;T<=S;T++){
			bool In[11]={0,0,0,0,0,0,0,0,0,0,0};
			for(int i=0;i<k;i++){
				if(T&(1<<i)) In[i+1]=1;
			}
			
			int cost=0;
			for(int i=1;i<=k;i++){
				if(In[i]){
					cost+=c[i][0];
					for(int j=1;j<=n;j++){
						v2.emplace_back((edge){n+i,j,c[i][j]});
					}
				}
			}
			kruskal(v2,n+k);
			v2.resize(m+1);
			res=min(res,ans+cost);
		} 
		//cout << res << endl;
		printf("%lld",res);
	}
	return 0;
}
