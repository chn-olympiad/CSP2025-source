#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int T,n,m,k,ans;
int w[15];
int f[N];
int head[10005],cnt=1;
struct node{
	int from,to,next,val;
}edge[N];
void add(int x,int y,int z){
	edge[cnt].from=x;
	edge[cnt].to=y;
	edge[cnt].val=z;
	edge[cnt].next=head[x];
	head[x]=cnt++;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
bool cmp(node x,node y){
 	return x.val<y.val;
}
int krus(){
	sort(edge+1,edge+cnt,cmp);
	int res=0;
//	cout<<edge[1].from<<endl;
	for(int i=1;i<cnt;i++){
		int x=find(edge[i].from),y=find(edge[i].to);
//		int x=0,y=0;
		if(x!=y){
			f[x]=y,res+=edge[i].val;
			if(edge[i].from>n) res+=w[edge[i].from-n];
			else if(edge[i].to>n) res+=w[edge[i].to-n];
		}
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&w[i]);
		for(int j=1,x;j<=n;j++){
			scanf("%lld",&x);
			add(n+i,j,x);
			add(j,n+i,x);
		} 
	}
	printf("%lld",krus());
	return 0;
}
