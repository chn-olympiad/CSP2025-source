#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2e4+5,M=2e6+5;
const ll INF=1e18;
int n,m,k,T;
int fa[N],Size[N],c[N],a[12][N],tmp[M],cnt[M];

inline int read(){
	int x=0;
	char c=getchar();
	while(c<48||c>57) c=getchar();
	while(c>=48&&c<=57){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x;
}

struct rec{
	int x,y,z;
	bool operator<(const rec &o)const{
		return z<o.z;
	}
}edge[M],b[M],d[M];

int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]); 
}

void Merge(int x,int y){
	x=get(x),y=get(y);
	if(x==y) return;
	if(Size[x]>Size[y]) swap(x,y);
	fa[x]=y;
	Size[y]+=Size[x]; 
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) edge[i].x=read(),edge[i].y=read(),edge[i].z=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read(); 
			tmp[++T]=a[i][j];
		}
	}
	sort(edge+1,edge+m+1);
	for(int i=1;i<=n;i++) fa[i]=i,Size[i]=1;
	int now=0;
	for(int i=1;i<=m;i++){
		int x=get(edge[i].x),y=get(edge[i].y);
		if(x==y) continue;
		Merge(x,y);
		b[++now]=edge[i];
		tmp[++T]=edge[i].z;
		if(now==n-1) break;
	}
	sort(tmp+1,tmp+T+1);
	T=unique(tmp+1,tmp+T+1)-tmp-1;
	for(int i=1;i<n;i++) b[i].z=lower_bound(tmp+1,tmp+T+1,b[i].z)-tmp;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++) a[i][j]=lower_bound(tmp+1,tmp+T+1,a[i][j])-tmp;
	}
	for(int i=1;i<n;i++) edge[i]=b[i];
	m=n-1;
	ll ans=INF;
	for(int i=0;i<1<<k;i++){
		for(int j=1;j<=m;j++) b[j]=edge[j];
		int t1=n,t2=m,ct=0;
		ll res=0;
		for(int j=0;j<k;j++){
			if(i>>j&1){
				t1++;
				res+=c[j+1];
				for(int l=1;l<=n;l++) b[++t2]={t1,l,a[j+1][l]};
			}
		}
		if(res>ans) continue;
		for(int j=1;j<=t1;j++) fa[j]=j,Size[j]=1;
		for(int j=1;j<=T;j++) cnt[j]=0;
		for(int j=1;j<=t2;j++) cnt[b[j].z]++;
		for(int j=1;j<=T;j++) cnt[j]+=cnt[j-1];
		for(int j=1;j<=t2;j++) d[cnt[b[j].z]--]=b[j];
		for(int j=1;j<=t2;j++) b[j]=d[j];
		for(int j=1;j<=t2;j++){
			int x=get(b[j].x),y=get(b[j].y);
			if(x==y) continue;
			Merge(x,y);
			ct++;
			res+=tmp[b[j].z];
			if(ct==t1-1||res>ans) break;
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}
