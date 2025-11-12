#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>inline void read(T&x){
	x=0; char c; int sign=1;
	do{c=getchar();if(c=='-') sign=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	x*=sign;
}

ll n,m,k,ans,cnt;
ll fa[10010],f[10010][10010];
struct node{
	int u,v,w;
};
node a[1100010];
ll c[10][10010];

ll find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}

bool cmp(node x,node y){
	return x.w<y.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	if(k<=0){
		for(int i=1;i<=m;i++){read(a[i].u); read(a[i].v); read(a[i].w);}
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			int fx=find(a[i].u); int fy=find(a[i].v);
			if(fx!=fy){
				ans+=a[i].w;
				fa[fx]=fy;
				cnt++;
				if(cnt==n-1) break;
			}
		}
		cout<<ans;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++) f[i][j]=0x3f3f3f3f;
	}
	for(int i=1;i<=m;i++){
		ll u,v,w;
		read(u); read(v); read(w);
		if(u>v) swap(u,v);
		f[u][v]=min(f[u][v],w);
	}
	int x;
	for(int i=1;i<=k;i++){
		read(x);
		for(int j=1;j<=n;j++){
			read(c[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int l=1;l<=k;l++){
				f[i][j]=min(f[i][j],c[l][i]+c[l][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[i][j]!=0x3f3f3f3f){
				a[++cnt].u=i; a[cnt].v=j; a[cnt].w=f[i][j];
			}
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++){
		int fx=find(a[i].u);
		int fy=find(a[i].v);
		if(fx!=fy){
			ans+=a[i].w;
			fa[fx]=fy;
			cnt++;
			if(cnt==n-1) break;
		}
	}
	cout<<ans;
	return 0;
}

