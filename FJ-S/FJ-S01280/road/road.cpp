#include<bits/stdc++.h>
using namespace std;
// T2 最小生成树
//考虑分层图 调出来了就AC 调不出来就 0分 
const int N=1e7+5;//会不会MLE啊 
int n,m,k;
int idx=m;
struct Edge{
	int u,v,w,st;
}a[N];
int fa[N],f[N],vg[N];//vg表示当前结点是新建的 

bool cmp(Edge x,Edge y){
	return x.w<y.w;
}

int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

void merge(int x,int y){
	int tx=find(x),ty=find(y);
	if(tx!=ty) fa[ty]=tx;//不会按秩合并应该没事吧... 
}
// 怎么感觉会TLE+MLE 
void krus(){
	//克鲁斯卡尔最小生成树
	int step=1;//记录有几个原来的城市在队列内 
	sort(a+1,a+idx+1,cmp);
	int ans=0,cnt=0;
	for(int i=1;i<=idx;i++){
		//复制的结点编号取模n以还原原本编号? 
		if(a[i].st<step) continue;//不能退回上一层 
		int tx=find(a[i].u),ty=find(a[i].v);
		
		if(tx!=ty){
			ans+=a[i].w;
			
			if(a[i].u%n==a[i].v%n && a[i].v>a[i].u){//只是下行一层，不算原结点个数 
				step++;//层数+1 
			}else{
				merge(a[i].u,a[i].v);
				if(a[i].u>0 || !f[a[i].u]){
					cnt++;
					f[a[i].u]=1;
				} 
				if(a[i].v>0 || !f[a[i].v]){
					cnt++;
					f[a[i].v]=1;
				} 
			}
			
			//cnt++;
			//cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<"cnt:"<<cnt<<'\n';
			
			if(cnt==n){//每一个原来的城市结点都在集合内
				cout<<ans;
				return ;
			}
		}
	}
}


void Krus(){
	sort(a+1,a+m+1,cmp);
	int ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		//复制的结点编号取模n以还原原本编号? 
		int tx=find(a[i].u),ty=find(a[i].v);
		
		if(tx!=ty){
			ans+=a[i].w;
			merge(a[i].u,a[i].v);
			if(++cnt==n-1){//每一个原来的城市结点都在集合内
				cout<<ans;
				return ;
			}
		}
	}
}
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].st=1;
	} 
	//这一堆肯定有问题 
	
	for(int i=1;i<=k;i++){
		//分层图试试
		//层数为i 
		int x;//下行一层的价格 
		cin>>x;
		for(int j=1;j<=n;j++){//枚举结点连接 
			a[++idx]={j,j+n*i,x,i+1};
		}
		for(int j=1;j<=m*k;j++){//把复制的结点间连起来 
			a[++idx]={a[j].u+n*i,a[j].v+n*i,a[j].w,i+1};
		}
		for(int j=1;j<=n;j++){
			int v;cin>>v;//和当前结点连起来 
			a[++idx]={j+n*i,-(n*(k+1)+1),v,i+1};
		}
		//输入写了30min	
	}
	for(int i=1;i<=idx;i++) fa[i]=i;
	if(k==0){
		Krus();
		return 0;
	} 
	krus();
	return 0;
}

/*
4 4 2 
1 4 6 
2 3 7 
4 2 5 
4 3 4 
1 1 8 2 4 
100 1 3 2 4 


*/
