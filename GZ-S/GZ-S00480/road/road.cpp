//GZ-S00480 安顺市第一高级中学 陈详镒菘 
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10005,MAXM = 1000006;

int cnt = 0,n,m,k;
struct edge{
	
	int u,v,cost;
	
}s[MAXM<<1];

bool cmp(edge a,edge b){
	
	return a.cost < b.cost;
	
}

void add_edge(int u,int v,int w){
	
	s[cnt].u = u;
	s[cnt].v = v;
	s[cnt].cost = w;
	cnt++;
	
	//printf("add edge %d connect %d %d cost %d\n",cnt,u,v,w);
	
	return;
}

int fa[MAXN],h[MAXN];

int find(int x){
	
	if(x == fa[x])return x;
	
	fa[x] = find(fa[x]);
	
	return fa[x];
	
}

void emerge(int a,int b){
	
	a = find(a);b = find(b);
	
	if(a==b)return;
	
	if(h[a] > h[b])swap(a,b);
	
	fa[a] = b;
	
	h[b] = max(h[a] + 1,h[b]);
	
	return;
	
}

int main () {
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d %d %d",&n,&m,&k);
	
	for(int i = 1;i <= n;i++)h[i] = 0;
	
	for(int i = 1;i <= m;i++){
		
		int u,v,c;scanf("%d %d %d",&u,&v,&c);
		
		add_edge(u,v,c);
		
	}
	
	for(int i = 1;i <= k;i++){
		
		int co;scanf("%d",&co);
		
		int w[MAXN],head;
		
		for(int j = 1;j <= n;j++){
			
			scanf("%d",&w[j]);
			
			if(w[j] == 0){
				
				head = j;
				
				
				
			}
			
			//printf("%d -> %d is %d\n",i,j,w[j]);
			
		}
		
		if(head != 0)for(int j = 1;j <= n;j++){
			
			if(j == head)continue;
			
			add_edge(j,head,w[j]);
			
		}
		
		//printf("village %d with head %d",i,head);
		
	}
	
	for(int i = 1;i <= n;i++)fa[i] = i;
	
	sort(s,s+cnt,cmp);
	
	long long ans = 0,cnty = 0;
	
	for(int i = 0;i <= cnt;i++){
		
		edge now = s[i];
		
		if(find(now.u) == find(now.v))continue;
		
		emerge(find(now.u),find(now.v));
		
		ans += now.cost;
		
		cnty++;
		
		//printf("choose edge %d connect %d %d cost %d\n",i,now.u,now.v,now.cost);
		
		if(cnty == n-1)break;
		
	}
	
	printf("%lld\n",ans);
	
	//printf("%d %d %d",n,m,k);
	
	return 0;
}
