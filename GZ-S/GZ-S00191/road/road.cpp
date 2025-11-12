// GZ-S00191 贵阳市南明区双龙华麟学校 徐文景 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,cnt,sumw;
struct edge{
	int u,v,w,next;
}r[1000005];
ll s,e,q,c[10][10005],root[10005],pre[10005];
void add(int u,int v,int w){
	r[++cnt].u=u;
	r[cnt].v=v;
	r[cnt].w=w;
	r[cnt].next=pre[v];
	pre[u]=u;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&s,&e,&q);
		add(s,e,q);
	}
	for(int i=1;i<=n;i++) r[i]=i;
	for(int i=1;i<=k;i++){
		cin >> c[i][0];
		for(int j=1;j<=n;j++){
			cin >> c[i][j];
		}
	}
	if(c[1][0]==0){
		cout << 0;
	}
	for(int i=1;i<=m;i++){
		sumw+=r[i].w;
	}
	cout << sumw;
	return 0;
}
