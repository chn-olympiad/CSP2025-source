#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define mk make_pair
#define N 10019
#define M 1000009
#define fi first
#define se second
#define K 10
using namespace std;
inline char nc(){static char buf[1<<20],*p=buf,*q=buf;return p==q&&(q=(p=buf)+fread(buf,1,1<<20,stdin),p==q)?EOF:*p++;}
inline ll rd(){bool f=0;char ch=nc();while(ch<'0'||ch>'9')f|=(ch=='-'),ch=nc();ll ans=0;while(ch>='0'&&ch<='9')ans=ans*10+ch-'0',ch=nc();return f?-ans:ans;}
char buf[1<<20],*p3=buf;inline void pc(char c){p3-buf<=1<<20?*p3++=c:(fwrite(buf,1,p3-buf,stdout),p3=buf,*p3++=c);}
inline void wt(ll x){if(x<0)x=-x,pc('-');if(x>9)wt(x/10);pc(x%10+'0');}
int n,m,k,fa[N],c[K];ll ans[1<<K];
pair<int,pair<int,int> >a[K][N];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
pair<int,pair<int,int> >e[M],f[1<<K][N];int t[1<<K];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road3.in","r",stdin);
//	freopen("Mikoto.txt","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(int i=1;i<=m;i++)e[i].se.fi=rd(),e[i].se.se=rd(),e[i].fi=rd();
	for(int i=0;i<k;i++){
		c[i]=rd();
		for(int j=1;j<=n;j++)a[i][j].fi=rd(),a[i][j].se=mk(i+n+1,j);
		sort(a[i]+1,a[i]+n+1);
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=find(e[i].se.fi),y=find(e[i].se.se);
		if(x==y)continue;
		f[0][++t[0]]=e[i],ans[0]+=e[i].fi,fa[x]=y;
	}
	for(int s=1;s<(1<<k);s++){
		int o=__lg(s),s1=s^(1<<o);
		for(int i=0;i<k;i++)if((s>>i)&1)ans[s]+=c[i];
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int i=1,j=1;
		while(i<=t[s1]&&j<=n){
			if(f[s1][i].fi<a[o][j].fi){
				int x=find(f[s1][i].se.fi),y=find(f[s1][i].se.se);
				if(x==y){i++;continue;}
				ans[s]+=f[s1][i].fi,fa[x]=y,f[s][++t[s]]=f[s1][i],i++;
			}
			else{
				int x=find(a[o][j].se.fi),y=find(a[o][j].se.se);
				if(x==y){j++;continue;}
				ans[s]+=a[o][j].fi,fa[x]=y,f[s][++t[s]]=a[o][j],j++;
			}
		}
		while(i<=t[s1]){
			int x=find(f[s1][i].se.fi),y=find(f[s1][i].se.se);
			if(x==y){i++;continue;}
			ans[s]+=f[s1][i].fi,fa[x]=y,f[s][++t[s]]=f[s1][i],i++;
		}
		while(j<=n){
			int x=find(a[o][j].se.fi),y=find(a[o][j].se.se);
			if(x==y){j++;continue;}
			ans[s]+=a[o][j].fi,fa[x]=y,f[s][++t[s]]=a[o][j],j++;
		}
	}
	ll res=ans[0];for(int s=1;s<(1<<k);s++)res=min(res,ans[s]);
	wt(res),pc('\n');
	fwrite(buf,1,p3-buf,stdout);
	return 0;
}
