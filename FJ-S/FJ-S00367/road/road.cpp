#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e4+10;
const int MAXM=1e6+10;
int n,m,k,fa[MAXN+10];
ll ans,sum;
bool f[20]={false};
struct node{
	int u,v;
	ll w,build_price;
}edge[MAXM+MAXN*10];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
int main(){
//	I hate CSP-S
//  最小生成树？ Why I have no answer? 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=find(edge[i].u),y=find(edge[i].v);
		if(x!=y){
			ans+=edge[i].w;
			fa[y]=x;
		}
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		sum=0;
		int a;
		cin>>a;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			edge[j+m*i].u=n+i;
			edge[j+m*i].v=j;
			edge[j+m*i].w=x;
			edge[j+m*i].build_price=a;
		}
		sort(edge+1,edge+m+n*i+1,cmp);
//		for(int j=1;j<=m+n*i;j++) cout<<edge[j].u<<" "<<edge[j].v<<" "<<edge[j].w<<endl;
		for(int j=1;j<=n+i;j++) fa[j]=j;
		for(int j=1;j<=m+n*i;j++){
			int x=find(edge[j].u),y=find(edge[j].v);
			if(x!=y){
				if(f[edge[j].u]==false){
					sum+=edge[j].build_price;
					f[edge[j].u]=true;
				}
//				cout<<edge[j].u<<" "<<edge[j].v<<" "<<edge[j].w<<endl;
//				cout<<edge[j].w<<" ";
				sum+=edge[j].w;
				fa[y]=x;
			}
		}
//		cout<<endl;
		ans=min(ans,sum);
//		cout<<sum<<endl;
//		if(ans>sum){
//			cout<<"变:"<<i<<endl;
//			ans=sum;
//		}
		if(ans==0){
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}

