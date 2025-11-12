#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 7;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
#define fo(i,n,m)	for(int i=n;i<=m;i++)
#define foo(i,n,m)	for(int i=n;i>=m;i--)
struct Node{
	int u,v,w;
}q[maxn];
int n,m,k;
int c[maxn];
int fa[maxn];
int p[maxn][maxn];
int find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
int zdl(){
	int cnt=0,sum=0;
	fo(i,1,m){
		int u=find(q[i].u),v=find(q[i].v);
		if(u!=v){
			fa[u]=v;
			cnt++;
			sum+=q[i].w;
			if(cnt==n-1){
				break;
			}
		}
	}
	return sum;
}
bool cmp(Node A,Node B){
	return A.w<B.w;
}
int AAA[maxn];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(p,inf,sizeof p);
	fo(i,1,n)	fa[i]=i;
	fo(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		q[i].u=u;
		q[i].v=v;
		q[i].w=w;
	}
	cout<<zdl()<<'\n';
	return 0;
}
