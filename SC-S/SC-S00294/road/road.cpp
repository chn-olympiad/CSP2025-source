#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll in(){
	ll k=0;
	bool f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=0;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+(c^48);
		c=getchar();
	}
	return f?k:-k;
}
void out(ll x){
	ll pos=0;
	char buf[20];
	if(x<0){
		putchar('-');
		x=-x;
	}
	buf[pos++]=x%10^48;
	x/=10;
	while(x){
		buf[pos++]=x%10^48;
		x/=10;
	}
	while(pos){
		putchar(buf[--pos]);
	}
}
void outel(ll x){
	out(x);
	putchar('\n');
}
ll n,m,k,c[10025],tot,a[10025][10025],dist[10025],ans;
bool vis[10025];
void prim(){
	ll xh=n;
	dist[1]=0;
	for(ll i=1;i<xh;i++){
		ll x=0;
		for(ll j=1;j<=n+k;j++){
			if(!vis[j]&&dist[j]+c[j]<dist[x]+c[x])x=j;
		}
		vis[x]=1;
		ans+=dist[x];
		if(x>n){
			ans+=c[x];
			xh++;
		}
		for(ll j=1;j<=n+k;j++){
			if(!vis[j])dist[j]=min(dist[j],dist[x]+a[j][x]);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	memset(dist,0x3f,sizeof(dist));
	n=in();m=in();k=in();
	for(ll i=1,u,v,w;i<=m;i++){
		u=in();v=in();w=in();
		a[u][v]=a[v][u]=w;
	}for(ll i=1;i<=k;i++){
		c[i+n]=in();
		for(ll j=1;j<=n;j++){
			a[n+i][j]=a[j][n+i]=in();
		}
	}
	prim();
	out(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}