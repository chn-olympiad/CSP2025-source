#include<bits/stdc++.h>
#define cint const int
#define ll long long
#define pii pair<int,int>
using namespace std;
cint N=1e7+5;
int n,m,k,cnt,bian;
int bcj[N],c[15];
bool fl[N];
ll ans=100000000000000;
struct node{
	int u,v;
	ll w;
}r[N];
bool cmp(node a,node b){return a.w<b.w;}
int find(int x){return bcj[x]==x?x:bcj[x]=find(bcj[x]);}
void dfs(int x,ll ew){
	if(x==cnt+1){		
		ll sum=ew;
		for(int j=1; j<=cnt; j++) bcj[j]=j;
		for(int j=1; j<=bian; j++){
			int x=find(r[j].u),y=find(r[j].v);
			if(x!=y && (fl[r[j].u] || r[j].u<=n) ){
				bcj[x]=y;
				//cout<<r[j].u<<':'<<r[j].w<<' ';
				sum+=r[j].w;
			}
		}
		//cout<<sum<<endl;
		ans=min(ans,sum);
		return;
	}
	dfs(x+1,ew);
	fl[x]=1;
	dfs(x+1,ew+c[x-n]);
	fl[x]=0;
}
int main()
{
 	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	cnt=n;
	for(int j=1; j<=m; j++){
		scanf("%d%d%lld",&r[j].u,&r[j].v,&r[j].w);
	}
	bool fl=0;
	bian=m;
	for(int j=1; j<=k; j++){
		scanf("%d",&c[j]);
		if(c[j]!=0) fl=1;
		cnt++;
		for(int i=1; i<=n; i++){
			ll l;
			scanf("%lld",&l);
			if(l!=0) fl=1;
			bian++;
			r[bian].u=cnt,r[bian].v=i,r[bian].w=l;
		}
	}
	if(!fl && k!=0){
		printf("0");
		return 0;
	}
	for(int j=1; j<=cnt; j++) bcj[j]=j;
	sort(r+1,r+bian+1,cmp);
	if(k==0){
		for(int j=1; j<=bian; j++){
			int x=find(r[j].u),y=find(r[j].v);
			if(x!=y && r[j].u<=n){
				bcj[x]=y;
				ans+=r[j].w;
			}
		}
	}else{
		dfs(n+1,0);
	}
	printf("%lld",ans);
	return 0;
}

