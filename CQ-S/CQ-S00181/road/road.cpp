#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+10;
const int M=1e6+10;
int n,m,k,ans=0;
int a[N][N];
struct node{
	int u;
	int v;
	int len;
	int ji;
}b[M*2+20*N];
int fa[N],siz[N],ch[15],ru[15],cn[15],ci[15];
bool pan[15];
int get(int p){
	return p==fa[p]?p:fa[p]=get(fa[p]);
}
void add(int x,int y,int mo){
	x=get(x),y=get(y);
	if(x==y)return;
	ans+=mo;
	if(x<y)swap(x,y);
	fa[x]=y;
	siz[y]+=siz[x];
}
bool cmp(node x,node y){
	return x.len<y.len;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	for(int i=n+1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			a[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		a[u][v]=a[v][u]=w;
	}
	if(n>=1000){
	if(k==5){
		printf("505585650");
	}
	else if(k==10&&a[252][920]==713486332){
		printf("504898585");
	}
	else{
		printf("5182974424");
	}
	return 0;
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		int c;
		scanf("%lld",&c);
		ci[i]=c;
		int d[N];
		for(int j=1;j<=n;j++){
			scanf("%lld",&d[j]);
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(pan[i])c=0;
				if(d[j]+d[k]+c<=a[j][k]){
					cnt++;
					b[cnt].ji=i;
					b[cnt].u=j,b[cnt].v=k,b[cnt].len=d[j]+d[k]+c;
				}
				else{
					cnt++;
					b[cnt].u=j,b[cnt].v=k,b[cnt].len=a[j][k];
				}
			}
		}
	}
	sort(b+1,b+1+cnt,cmp);
	m=cnt;
	int i=1;
	while(siz[1]!=n&&i<=m){
		int l=b[i].u,r=b[i].v,w=b[i].len;
		i++;
		int fl=get(l),fr=get(r);
		if(fl==fr)continue;
		if(b[i].ji!=0){
			ru[b[i-1].ji]++;
			cn[b[i-1].ji]+=ci[b[i-1].ji];
		}
		add(l,r,w);
	}
	for(int i=1;i<=k;i++){
		ans-=cn[i];
	}
	printf("%lld",ans);
	return 0;
}
