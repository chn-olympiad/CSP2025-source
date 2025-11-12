#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define endl "\n"
using namespace std;
int n,m,k,ans,Max,sum=inf;
struct node{
	int u,v,w,flag;
}edge[1000010];
int cnt[1000010],f[1000010],c[100010];
int a[20][10010];
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
bool cmp(node a,node b){
	return a.w<b.w;
}
void start(int n){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
}
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x!=y)f[y]=x;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	start(n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
		edge[i].flag=0;
		Max=max(Max,edge[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	int t;
	sort(edge+1,edge+1+n,cmp);
	for(int i=1;i<=n;i++){
		int x=find(edge[i].u),y=find(edge[i].v);
		if(x==y)continue;
		if(cnt[y]>n)continue;
		f[y]=x;
		cnt[y]++;
		ans+=edge[i].w;
	}
	t=ans;
	ans=0;
	for(int i=1;i<=k;i++){
		int tmp=n;
		if(c[i]>=Max)continue;
		ans+=c[i];
		for(int j=1;j<=tmp;j++){
			edge[++n]={tmp+1,j,a[i][j],1};
		} 
		n++;
		start(n);
		sort(edge+1,edge+1+n,cmp);
		int flag=1;
//		for(int i=1;i<=n;i++){
//			cout<<edge[i].u<<' '<<edge[i].v<<' '<<edge[i].w<<' '<<edge[i].flag<<endl;
//		}
		for(int i=1;i<=n;i++){
			int x=find(edge[i].u),y=find(edge[i].v);
			if(x==y)continue;
			if(cnt[y]>n)continue;
			f[y]=x;
			cnt[y]++;
			ans+=edge[i].w;
			if(edge[i].flag)flag=0;
		}
		if(!flag){
			if(ans>sum){
				ans=0;
				n=tmp; 
			}else sum=ans;
		}
		else{
			ans=0;
			n=tmp;
		}
	}
	printf("%lld",min(sum,t));
	return 0;
} 

