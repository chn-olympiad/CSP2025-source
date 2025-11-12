//I Love CCF.I Want 100pts in this problem!
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void read(ll &x){
	x=0;ll f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=f;
}
void read(int &x){
	x=0;ll f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=f;
}
const int N=1e4+59,M=1e6+2;
struct ed{
	int u,v,w;
}e[M];
bool cmp(ed a,ed b){
	return a.w<b.w;
}
int n,nown,m,k;
int c,a[N];
int head[N],nxt[M<<1],to[M<<1],w[M<<1],tot;
void add(int u,int v,int wa){
	to[++tot]=v,nxt[tot]=head[u],w[tot]=wa,head[u]=tot;
}
ll dis[N];int siz[N],dfn[N],cnt;
struct segment_tree_orz{
	ll s[N<<2],tag[N<<2];
	void build(ll *a,int p,int pl,int pr){
		tag[p]=0;
		if(pl==pr){s[p]=a[pl];return;}
		int mid=(pl+pr)>>1;
		build(a,p<<1,pl,mid);
		build(a,p<<1|1,mid+1,pr);
		s[p]=s[p<<1]+s[p<<1|1];
	}
	void pushdown(int p,int pl,int pr){
		int mid=(pl+pr)>>1;
		s[p<<1]+=tag[p]*(mid-pl+1);
		tag[p<<1]+=tag[p];
		s[p<<1|1]+=tag[p]*(pr-mid);
		tag[p<<1|1]+=tag[p];
		tag[p]=0;
	}
	void add(int p,int pl,int pr,int l,int r,int k){
		if(pl>=l and pr<=r){
			s[p]+=k*(pr-pl+1);
			tag[p]+=k;
			return;
		}
		pushdown(p,pl,pr);
		int mid=(pl+pr)>>1;
		if(mid>=l) add(p<<1,pl,mid,l,r,k);
		if(mid<r) add(p<<1|1,mid+1,pr,l,r,k);
		s[p]+=s[p<<1]+s[p<<1|1];
	}
	ll query(int p,int pl,int pr,int l,int r){
		if(pl>=l and pr<=r) return s[p];
		pushdown(p,pl,pr);
		int mid=(pl+pr)>>1;
		ll res=0;
		if(mid>=l) res=query(p<<1,pl,mid,l,r);
		if(mid<r) res+=query(p<<1|1,mid+1,pr,l,r);
		return res;
	}
}t1,t2;
int s[N];
int find(int x){
	return x==s[x]?x:s[x]=find(s[x]);
}
void MST(){
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) s[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break;
		if(find(e[i].u)!=find(e[i].v)){
			s[find(e[i].u)]=s[find(e[i].v)];
			add(e[i].u,e[i].v,e[i].w),add(e[i].v,e[i].u,e[i].w);
			cnt++;
		}
		else continue;
	}
}//pao zui xiao sheng cheng shu
void dfs(int x,int fa,ll nw){
	//cout<<x<<endl;
	dfn[x]=++cnt,dis[x]=nw,siz[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(y==fa) continue;
		dfs(y,x,nw+w[i]);
		siz[x]+=siz[y];
	}
}//pao DFS qiu dis he siz yi ji dfn
ll ans=0,ans1=0;
void dfs1(int x,int fa){
	ll k=t2.query(1,1,n,dfn[x],dfn[x]);
	if(((k-a[x])*siz[x]>a[x])){//yi ding yaoshengxia qian cai ke yi bei kao lu!
		ans+=(k-a[x])*siz[x];
		t2.add(1,1,n,dfn[x],dfn[x]+siz[x]-1,a[x]-k);
		ans1+=a[x];//hua fei ye yao jia shang,ciallo~
	}
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(y==fa) continue;
		dfs1(y,x);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++)
		read(e[i].u),read(e[i].v),read(e[i].w);
	MST();//cout<<"why?\n";
	//for(int i=1;i<2*n-1;i++) cout<<to[i]<<" "<<nxt[i]<<" "<<w[i]<<" "<<i<<'\n';
	dfs(1,-1,0);
	//cout<<"why?\n";
	ll sum=0;
	for(int i=1;i<=m*2;i++) sum+=w[i];
	sum/=2;
	cout<<sum<<endl;
	t1.build(dis,1,1,n);//jian xian duan shu
	//cout<<"why"<<endl;
	for(int i=1;i<=k;i++){
		bool flag=0;
		read(c);if(c!=0) flag=1;
		for(int j=1;j<=n;j++){
			read(a[dfn[j]]);
			if(a[dfn[j]]!=0) flag=1;
		}
		if(!flag){
			cout<<0<<'\n';//te shu xing zhi A
			return 0;
		}
		ans1=c+a[1];
		t2.build(dis,1,1,n);//jian xian duan shu
		dfs1(1,-1);
		//cout<<ans<<" "<<ans1<<'\n';
		if(ans<=ans1) continue;//na jiu bu bian le
		for(int i=1;i<=n;i++) dis[i]=t2.query(1,1,n,i,i);
		sum-=(ans-ans1);
	}
	cout<<sum<<'\n';
	return 0;
}
/*
  4 4 2
  1 4 6
  2 3 7
  2 4 5
  4 3 4
  1 1 8 2 4
  100 1 3 2 4
*/
//I only have 172pts,can i go to NOIP(sad)?i want to go it!
//my names in Luogu is JadeFox2012
