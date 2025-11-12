#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10+10;
const int M=1e6+1e5+10;
bool can[N],vis[N];
int n,m,k,u[M],v[M],w[M],c[N],fa[N],ans=0x3f3f3f3f3f3f3f3f,tot,edge[M],sum;
int find(int x){
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
void merge(int x,int y){
	if(x!=y){
		fa[x]=y;
	}
}
bool cmp(int x,int y){
	return w[x]<w[y];
}
void kkk(){
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int rp=1;rp<=sum;rp++){
		int i=edge[rp];
		if((!can[u[i]])||(!can[v[i]]))continue;
		int x=find(u[i]),y=find(v[i]);
		if(x==y)continue;
		// cout<<u[i]<<' '<<v[i]<<' '<<w[i]<<endl;
		merge(x,y);
		tot+=w[i];
	}
}
signed main(){
	 freopen("road.in","r",stdin);
	 freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
//	for(int i=1;i<=n;i++)can[i]=1;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		can[u[i]]=can[v[i]]=1;
		edge[++sum]=i;
	}
	bool flg=1;
	int xxx;
	if(n<=1000&&m<=100000){
		for(int i=1;i<=k;i++){
			cin>>c[i];
			if(c[i]!=0)flg=0;
			for(int j=1;j<=n;j++){
				int tmp=m+(i-1)*n+j;
				u[tmp]=n+i;
				v[tmp]=j; 
				cin>>w[tmp];
				edge[++sum]=tmp;
			}
		}
		sort(edge+1,edge+1+sum,cmp);
		for(int i=0;i<=(1<<(k))-1;i++){
			tot=0;
			for(int j=1;j<=k;j++){
				if((i&((1<<(j-1))))){
					can[n+j]=1;
					tot+=c[j];
				}
			}
			kkk();//kkk means krus??? (那个算法名称不会拼) luogu uid = 1401495
			for(int j=1;j<=k;j++){
				can[n+j]=0;
			}
			ans=min(ans,tot);
			// cout<<tot<<'\n';
		}
	}
	else{
		flg=1;
		for(int i=1;i<=k;i++){
			cin>>c[i];
			can[n+i]=1;
			for(int j=1;j<=n;j++){
				int tmp=m+(i-1)*n+j;
				u[tmp]=n+i;
				v[tmp]=j; 
				cin>>w[tmp];
				edge[++sum]=tmp;
			}
		}
		sort(edge+1,edge+1+sum,cmp);
		kkk();
		
		xxx=tot;
	}
	if(flg)ans=xxx;
	cout<<ans;
}
