#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50,M=1e6+50;
typedef long long ll;
const ll inf=4e18+7;
int n,m,k;
struct edge{
	int u,v;
	ll w;
}a[M*2];
ll c[15],w[15][N];
int idx,idx2;
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
ll ans=inf;
inline bool cmp(edge x,edge y){
	return x.w<y.w;
}
inline ll check(){
	sort(a+1,a+idx+1,cmp);
	for(int i=1;i<=n+idx2;i++) fa[i]=i;
	int cnt=0;
	ll res=0;
	for(int i=1;i<=idx;i++){
		if(find(a[i].u)==find(a[i].v)) continue;
		fa[find(a[i].u)]=find(a[i].v);
		cnt++;
		res+=a[i].w;
		if(cnt==n+idx2-1) break;
	}
	return res;
}
inline ll read(){
	ll x=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		c=getchar();
	} 
	while(c>='0' && c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	n=read(),m=read(),k=read();
	idx=m,idx2=n;
	for(int i=1;i<=m;i++){
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) w[i][j]=read();
	}
	ans=check();
	ll tmp=0;
	for(int i=1;i<=k;i++){
		idx2++;
		tmp+=c[i];
		for(int j=1;j<=n;j++){
			a[++idx].u=n+i;
			a[idx].v=j;
			a[idx].w=w[i][j];
		}
		ll d=check();
//		cout<<tmp<<" "<<d<<endl;
		if(tmp+d>ans){
			idx-=n;
			idx2--;
			tmp-=c[i];
		}
		else ans=tmp+d;
	}
	printf("%lld",ans);
	return 0;
}
