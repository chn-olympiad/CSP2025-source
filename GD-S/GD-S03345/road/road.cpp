#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+15,M = 1e6+15;
const ll INF = 1e17;
ll read(){
	ll x=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-'){w=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*w;
}
int n,m,k;
struct node{
	int x,y;
	ll val;
}e[M];
bool cmp(node X,node Y){
	return X.val < Y.val;
}
int fa[N];
ll a[2025][N],ans[2025];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int x,y;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i = 1;i <= m;++i){
		e[i].y=read(),e[i].x=read();
		e[i].val=read();
	}
	for(int i = 1;i <= n;++i)fa[i]=i;
	memset(a,0x3f,sizeof(a));
	memset(ans,0x3f,sizeof(ans));
	ans[0]=0;
	for(int i = 0;i < k;++i){
		ans[1<<i]=read();
		for(int j = 1;j <= n;++j){
			a[1<<i][j]=read();
		}
	}
	for(int i = 1;i < (1<<k);++i){
		int T = i&-i;
		ans[i] = ans[i^T]+ans[T];
		for(int j = 1;j <= n;++j){
			a[i][j]=min(a[i^T][j],a[T][j]);
		}
	}
	sort(e+1,e+m+1,cmp);
	int tot = 0;
	for(int j = 1;j <= m;++j){
		x=find(e[j].x),y=find(e[j].y);
		if(x!=y){
			for(int i = 1;i < (1<<k);++i){
				ans[i]+=min(a[i][x]+a[i][y],e[j].val);
				if(min(a[i][x]+a[i][y],e[j].val)==a[i][x]+a[i][y]){
					a[i][y]=0;
				}
				else a[i][y]=min(a[i][x],a[i][y]);
			}
			ans[0]+=e[j].val;
			fa[x]=y;
			++tot;
		}if(tot==n-1)break;
	}
	ll su=ans[0];
	for(int i = 1;i < (1<<k);++i){
		su = min(su,ans[i]);
	}
	printf("%lld",su);
	return 0;
} 
