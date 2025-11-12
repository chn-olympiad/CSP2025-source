#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,a[100][10010],c[100],ans=1e18,fa[1000010];
int find(int x){
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}
void unite(int x,int y){
	x=find(x),y=find(y);
	fa[y]=x;
}
struct Edge{
	int u,v,w;
	bool operator<(const Edge x)const{
		return w>x.w;
	}
};
priority_queue<Edge>q;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		q.push((Edge){u,v,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=0;i<(1<<k);i++){
//		cout<<i<<":\n:";
		int sum=0,num=n-1;
		priority_queue<Edge>qq;
		qq=q;
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
//				cout<<j<<" ";
				num++;
				sum+=c[j];
				for(int l=1;l<=n;l++){
					qq.push((Edge){l,n+j,a[j][l]});
				}
			}
		}
//		cout<<'\n';
		while(num>0){
			Edge x=qq.top();
			qq.pop();
			if(find(x.u)!=find(x.v)){
//				cout<<x.u<<" "<<x.v<<'\n';
				unite(x.u,x.v);
				num--;
				sum+=x.w;
			}
		}
		ans=min(ans,sum);
//		cout<<sum<<'\n';
	}
	printf("%lld",ans);
	return 0;
}

