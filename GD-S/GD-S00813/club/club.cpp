#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x*=f;
	return;
}
template<typename T>
inline void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
bool Mbe;
typedef long long ll;
typedef pair<int,int> PII;
const int N=1e5+5;
int n,a[N][3],cnt[3];
bool tag[N];
ll ans=0;
struct Node{
	int v,x,y;
	Node(){}
	Node(int _v,int _x,int _y):v(_v),x(_x),y(_y){}
	bool operator < (const Node& b)const{
		return v<b.v;
	}
};
priority_queue<Node> q;
vector<int> g[3];
void work(int x,int y,int z){
//	cout<<x<<":\n";
	for(int i=0;i<g[x].size();i++){
		int v=g[x][i];
//		cout<<v<<' ';
		tag[v]=false;
		q.push(Node(a[v][y]-a[v][x],v,y));
		q.push(Node(a[v][z]-a[v][x],v,z));
	}
//	cout<<'\n';
//	cout<<ans<<'\n';
	int ret=0;
	while(!q.empty()){
		int v=q.top().v,i=q.top().x;
		q.pop();
		if(tag[i]||cnt[x]-ret<=n/2) continue;
//		cout<<v<<' '<<i<<'\n';
		ans+=v,tag[i]=true,ret++;
	}
}
void solve(){
	read(n);
	for(int i=0;i<3;i++) cnt[i]=0,g[i].clear();
	for(int i=1;i<=n;i++) tag[i]=false;
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++){
			read(a[i][j]);
			q.push(Node(a[i][j],i,j));
		}
	ans=0;
	while(!q.empty()){
		int v=q.top().v,i=q.top().x,j=q.top().y;
		q.pop();
		if(tag[i]) continue;
		ans+=v,tag[i]=true,cnt[j]++,g[j].emplace_back(i);
	}
	if(cnt[0]>n/2) work(0,1,2);
	if(cnt[1]>n/2) work(1,0,2);
	if(cnt[2]>n/2) work(2,0,1);
	write(ans);
	putchar('\n');
}
bool Med;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int c=1,T=1;
	read(T); 
	while(T--) solve();
//	cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB"<<'\n';
	return 0;
} 
/*
O(nlogn)
*/ 
