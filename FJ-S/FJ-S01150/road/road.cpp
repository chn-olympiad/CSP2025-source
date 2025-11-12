#include<bits/stdc++.h>
using namespace std;
void dd(int &ss){
	ss=0;
	char ch=getchar();int ff=1;
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while('0'<=ch&&ch<='9')ss=ss*10+ch-'0',ch=getchar();
	ss*=ff;
}
const int N=5e6+5;
int m;
int n,bb[N],k,pp[N],zz[N];
int minn[N],ct[N],a[N];
long long ans=1e16;
int siz[N],fa[N];
struct aaa{
	int x,y,z;
}t[N],tx[N],ty[N];
int cnt,cnty;
bool cmp(aaa x,aaa y){
	return x.z<y.z;
}
void hb(int x,int y){
	if(siz[x]>siz[y])swap(x,y);
	fa[x]=y;
	siz[y]+=x;
}
int fid(int x){
	return x==fa[x]?x:fa[x]=fid(fa[x]);
}
long long ppp(){
	long long anss=0;
	for(int i=1;i<=n+k;++i)fa[i]=i,siz[i]=1,pp[i]=0;
	for(int i=1;i<=k;++i)
	if(bb[i])hb(i+n,minn[i]),anss+=ct[i];
	if(anss>ans)return anss;
	int j=1;
	for(int i=1;i<=cnt;++i){
		while(j<=cnty&&ty[j].z<=tx[i].z){
			if(!pp[ty[j].y]&&bb[ty[j].x-n]){
				int fx=fid(ty[j].x),fy=fid(ty[j].y);
				if(fx!=fy){
					hb(fx,fy);
					anss+=ty[j].z;
				}
				pp[ty[j].y]=1;
			}
			++j;
		}
		int fx=fid(tx[i].x),fy=fid(tx[i].y);
		if(fx!=fy){
			hb(fx,fy);
			anss+=tx[i].z;
		}
		if(anss>ans)return anss;
	}
	return anss;
}
void dfs(int x){
	if(x==k+1){
		ans=min(ans,ppp());
		return ;
	}
	bb[x]=1;
	dfs(x+1);
	bb[x]=0;
	dfs(x+1); 
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	dd(n),dd(m),dd(k);
	for(int i=1;i<=m;++i)
	dd(t[i].x),dd(t[i].y),dd(t[i].z);
	for(int i=1;i<=n;++i)fa[i]=i,siz[i]=1;
	sort(t+1,t+m+1,cmp);
	for(int i=1;i<=m;++i){
		int fx=fid(t[i].x),fy=fid(t[i].y);
		if(fx!=fy){
			hb(fx,fy),tx[++cnt]=t[i];
		}
	}
	for(int i=1;i<=k;++i){
		dd(zz[i]);
		for(int j=1;j<=n;++j){
			dd(a[j]);
			if(a[minn[i]]>a[j]||!minn[i])minn[i]=j,ct[i]=a[j]+zz[i];
		}
		for(int j=1;j<=n;++j)
		if(j!=minn[i])ty[++cnty].x=i+n,ty[cnty].y=j,ty[cnty].z=a[j];
	}
	sort(ty+1,ty+cnty+1,cmp);
	dfs(1);
	cout<<ans;
}
