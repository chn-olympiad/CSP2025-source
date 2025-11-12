#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define int long long
//#define int __int128
//#define int unsigned int
//#define mod
using namespace std;
void fio(string s,int i){
	freopen((s+(i?to_string(i):"")+".in").c_str(),"r",stdin);
	freopen((s+(i?to_string(i):"")+".out").c_str(),"w",stdout);
}
inline int read(){
	int ret=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}return ret*f;
}
inline void write(int x,int op=0){
	if(x<0){
		putchar('-');
		x=-x;
	}
	stack<char>qwq;
	while(!qwq.empty())qwq.pop();
	while(x>9){
		qwq.push(x%10+'0');
		x/=10;
	}
	qwq.push(x+'0');
	while(!qwq.empty())putchar(qwq.top()),qwq.pop();
	if(op>0)putchar('\n');
	if(op<0)putchar(' ');
}
const int N=1e4+5,M=1e6+10,K=1<<11;
int n,m,k;
int ans=1e18;
struct node{
	int u,v,w;
	friend bool operator <(node a,node b){
		return a.w<b.w;
	}
}e[M],awa[N];
vector<node>qwq;
int fa[N+10];
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]); 
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return ;
	fa[y]=x;
}
int temp;
int c[15];
int a[15][N];
signed main(){
	fio("road");
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)e[i]={read(),read(),read()};
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	for(int i=0;i<(1<<k);i++){
		if(i==0){
			int ret=0;
			for(int j=1;j<=n;j++)fa[j]=j;
			for(int j=1;j<=m;j++)qwq.push_back(e[j]);
			sort(qwq.begin(),qwq.end());
			for(node tmp:qwq){ 
				int u=tmp.u,v=tmp.v,w=tmp.w;
				if(find(u)==find(v))continue;
				ret+=w;
				awa[++temp]=tmp;
				merge(u,v);
			}ans=min(ans,ret);
			qwq.clear();
		}else{
			int ret=0;
			for(int j=1;j<=n+k;j++)fa[j]=j;
			for(int j=1;j<=temp;j++)qwq.push_back(awa[j]);
			for(int j=1;j<=k;j++){
				if((i>>(j-1))&1){
					ret+=c[j];
					for(int l=1;l<=n;l++)qwq.push_back({n+j,l,a[j][l]});
				}
			}
			sort(qwq.begin(),qwq.end());
			for(node tmp:qwq){ 
				int u=tmp.u,v=tmp.v,w=tmp.w;
				if(find(u)==find(v))continue;
				ret+=w;
				merge(u,v);
			}ans=min(ans,ret);
			qwq.clear();
		} 
	}write(ans);
	return 0;
}
/*
先求一遍最小生成树
然后做一遍树形dp？
接着对每一条边更新
这个更新肯定是要做到O 1的 
原来如此，乐 
*/

