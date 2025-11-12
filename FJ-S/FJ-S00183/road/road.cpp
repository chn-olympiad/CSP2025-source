#include<bits/stdc++.h>
using namespace std;
const int N=10105;
const int M=1e6+5;
const int K=15;
int n,m,k,fa[N],c[K],a[K][N],tp,bk[N];
long long ans;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct qwq{
	int u,v,w;
}p[M],e[M];
bool cmp(qwq a,qwq b){
	return a.w<b.w;
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
int main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)p[i].u=read(),p[i].v=read(),p[i].w=read();
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		int t1=find(p[i].u),t2=find(p[i].v);
		if(t1==t2)continue;
		fa[t1]=t2;
		e[++tp]=p[i];
		ans=ans+p[i].w;
		cnt++;
		if(cnt==n-1)break;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			tp++;
			e[tp].u=j,e[tp].v=n+i,e[tp].w=a[i][j];
		}
	}
	sort(e+1,e+tp+1,cmp);
	for(int i=0;i<(1<<k);i++){
		int l=n,cnt=0;
		long long res=0;
		for(int j=1;j<=k;j++)bk[n+j]=(i>>(j-1))&1;
		for(int j=1;j<=k;j++)l+=bk[n+j];
		for(int j=1;j<=k;j++)if(bk[n+j])res+=c[j];
		for(int j=1;j<=n+k+1;j++)fa[j]=j;
		for(int j=1;j<=tp;j++){
			if(e[j].v>n&&bk[e[j].v]==0)continue;
			int t1=find(e[j].u),t2=find(e[j].v);
			if(t1==t2)continue;
			fa[t1]=t2;
			res+=e[j].w;
			cnt++;
			if(cnt==l-1){
				break; 
			}
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
