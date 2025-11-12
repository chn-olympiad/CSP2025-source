#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
const int INF=0x3f;
int h[N],e[M],ne[M],w[M],tot,fa[N],d[N];
bool v[N];
struct chang{
	int c;
	int a[N];
	int sum;
}ci[N];
void add(int x,int y,int z){
	tot++;
	e[tot]=y;
	w[tot]=z;
	ne[tot]=h[x];
	h[x]=tot;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int n,m,k;
queue<int> q;
int ans;
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	
	for(int i=1;i<=k;i++){
		cin>>ci[i].c;
		ci[i].sum=ci[i].c;
		for(int j=1;j<=n;j++){
			cin>>ci[i].a[j];
			ci[i].sum+=ci[i].a[j];
		}
	}
	memset(d,INF,sizeof(d));
	q.push(1);
	v[1]=1;
	d[1]=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	while(q.size()!=0){
		int u=q.front();
		q.pop();
		for(int i=h[u];i!=0;i=ne[i]){
			int x=e[i],z=w[i];
		//	if(find(x)==find(u))continue;
			if(d[x]>d[u]+z){
				d[x]=d[u]+z;
				if(v[x]==0){
					q.push(x);
					v[x]=1;
				}
				fa[x]=find(u);
				for(int j=1;j<=n;j++){
					if(find(j)==find(x)){
					    d[j]=min(d[j],d[x]+d[u]);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans+=d[i];
	}
	cout<<ans;
	return 0;
}/*
4 5 1
1 2 1
1 4 2
2 3 4
2 4 3
3 4 5
*/
