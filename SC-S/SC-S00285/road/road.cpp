#include<bits/stdc++.h>
const long long N=1e4+5,M=1e6+5,K=11,inf=1e18;
int n,m,k,flag=1,cur[K],c[K],vis[K],f[M],h[M];
long long ans=inf;
struct node{
	int u,v,w;
	friend bool operator < (node a,node b){
		return a.w<b.w;
	}
}a[M],b[K][N];
int find(int u){
	if(f[u]==u)return u;
	return f[u]=find(f[u]);
}
int merge(int a,int b){
	a=find(a),b=find(b);
	if(a==b)return 0;
	if(h[a]<h[b])std::swap(a,b);
	f[b]=a;
	if(h[a]==h[b])h[a]++;
	return 1;
}
void dfs(int step,long long sum,int cs){
	if(step>k){
		int cnt=0;
		for(int i=0;i<=k;i++)cur[i]=1;
		for(int i=0;i<=n+k;i++)f[i]=i,h[i]=0;
		while(cnt<n+cs-1){
			long long min=cur[0]>m?inf:a[cur[0]].w;
			for(int i=1;i<=k;i++){
				if(vis[i]&&cur[i]!=n+1)min=std::min(min,(long long)b[i][cur[i]].w);
			}
//			printf("%d %lld %lld %d\n",cnt,sum,min,n+cs-1);
//			for(int i=0;i<=k;i++)printf("%d ",cur[i]);
//			printf("\n");
			if(cur[0]<=m&&a[cur[0]].w==min){
//				printf("			%d %d\n",a[cur[0]].u,a[cur[0]].v);
				if(merge(a[cur[0]].u,a[cur[0]].v))sum+=a[cur[0]].w,cnt++;
				cur[0]++;
				while(cur[0]<=m&&find(a[cur[0]].u)==find(a[cur[0]].v))cur[0]++;
			}
			for(int i=1;i<=k;i++){
				if(vis[i]&&cur[i]<=n&&b[i][cur[i]].w==min){
//					printf("2\n");
					if(merge(b[i][cur[i]].u,b[i][cur[i]].v))sum+=b[i][cur[i]].w,cnt++;
					cur[i]++;
					while(cur[i]<=n&&find(b[i][cur[i]].u)==find(b[i][cur[i]].v))cur[i]++;
				}
			}
		}
//		printf("\n%d\n\n",sum);
		ans=std::min(ans,sum);
		return ;
	}
	if(!flag)dfs(step+1,sum,cs);
	vis[step]=1;
	dfs(step+1,sum+c[step],cs+1);
	vis[step]=0;
}
void read(int &a){
	char ch=getchar();
	a=0;
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='9'&&ch>='0')a=a*10+ch-'0',ch=getchar();
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		read(a[i].u),read(a[i].v),read(a[i].w);
	}
	std::sort(a+1,a+m+1);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		flag&=c[i]==0;
		for(int j=1;j<=n;j++){
			read(b[i][j].w);
			b[i][j]={i+n,j,b[i][j].w};
		}
		std::sort(b[i]+1,b[i]+n+1);
	}
	dfs(1,0,0);
	printf("%lld",ans);
}