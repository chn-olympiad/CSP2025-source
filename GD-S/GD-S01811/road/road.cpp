#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

namespace FastIO{
	inline ll read(){
		ll s=0,f=1;char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-')f=-1;
			c=getchar();
		}
		while('0'<=c&&c<='9'){
			s=(s<<1)+(s<<3)+c-'0';
			c=getchar();
		}
		return s*f;
	}
}
using FastIO::read;
const int N = 10010;
const int M = 1110000;
const int K = 11;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n,m,k,kk;
ll ans,a[K][N],rans;
struct line{
	int u,v;ll val;
}l[M<<1];
int h[N],cnt,aa,bb;
ll cc;
void link(int u,int v,ll val){
	l[++cnt]=(line){h[u],v,val};h[u]=cnt;
	l[++cnt]=(line){h[v],u,val};h[v]=cnt;
}
int f[N];
int getfa(int x){
	if(f[x]==x)return x;
	f[x]=getfa(f[x]);
	return f[x];
}
void mErged(int x,int y){
	int a=getfa(x),b=getfa(y);
	if(a==b)return;
	f[b]=a;
}
struct info{
	int u,v;ll val;
}edg[M];
bool cmp(info a,info b){
	return a.val<b.val;
} 
int mm,gnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	rans=inf;
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)edg[i].u=read(),edg[i].v=read(),edg[i].val=read();
	for(int i=1;i<=k;i++)for(int j=0;j<=n;j++)a[i][j]=read();
	kk=(1<<k);
	for(int i=0,j,d,cnt=0;i<kk;i++){
		memset(f,0,sizeof(f));
		mm=m;j=i;d=0;cnt=0;gnt=0;ans=0;
		for(int i=1;i<=n;i++)f[i]=i;
		while(j){
			++d;
			if(j%2){
				ans+=a[d][0];gnt++;f[n+d]=n+d;
				for(int l=1;l<=n;l++)edg[++mm].u=n+d,edg[mm].v=l,edg[mm].val=a[d][l]; 
			}j/=2;
		}
		stable_sort(edg+1,edg+1+mm,cmp);
		for(int l=1;l<=mm;l++){
			if(getfa(edg[l].u)!=getfa(edg[l].v)){
				mErged(edg[l].u,edg[l].v);
				ans+=edg[l].val;cnt++;
				//cout<<i<<"add"<<ans<<'\n';
			}
			if(cnt==gnt+n-1)break;
		}
		rans=min(rans,ans);
	}
	cout<<rans<<'\n';
	
	
	return 0;
}
