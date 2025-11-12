#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN=1e7;
struct NewNode {
	int u,v,w;
};
NewNode Node[MAXN];
int p[10005];
int a[10005];

bool cmp(NewNode a,NewNode b){
	return a.w<b.w;
}

int find(int x){
	return p[x]==x?p[x]:p[x]=find(p[x]);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>Node[i].u>>Node[i].v>>Node[i].w;
	}
	int v=m;
	for(int i=1; i<=k; i++) {
		int x;
		cin>>x;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; i<=n; i++) {
				v++;
				Node[v].u=i;
				Node[v].v=j;
				Node[v].w=a[i]+a[j]+x;
			}
		}
	}
	sort(Node+1,Node+v+1,cmp);
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	long long ans=0,cnt=0;
	for(int i=1;i<=v;i++){
		int u=Node[i].u;
		int v=Node[i].v;
		if(find(u)!=find(v)){
			ans+=Node[i].w;
			cnt++;
			p[u]=v;
			if(cnt==n-1) break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
