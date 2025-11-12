#include<bits/stdc++.h>
using namespace std;

const int M=1e4+15;
inline int rd(){
	int res=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0')res=res*10+c-'0',c=getchar();
	return res;
}
inline void wt(long long x){
	if(x>9)wt(x/10);
	putchar(x%10+'0');
}
int n,m,k,pw[11],fa[M],cnt,ret[11][M],siz[M];
long long st[11],a[11][M];
int gf(int x){
	if(fa[x]!=fa[fa[x]])fa[x]=gf(fa[x]);
	return fa[x];
}
struct node{
	int u,v,id;
	long long w;
}e[100*M],pp[M],nw[11*M];
bool flag[11];
inline const bool cmp(const node &s1,const node &s2){
	return s1.w<s2.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=10;++i)pw[i]=pw[i-1]*2;
	n=rd(),m=rd(),k=rd();
//	cerr<<n<<' '<<m<<' '<<k<<endl;
	for(int i=1;i<=m;++i){
		e[i].u=rd(),e[i].v=rd(),e[i].w=rd();
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		if(gf(e[i].u)!=gf(e[i].v)){
			nw[++cnt].u=e[i].u;
			nw[cnt].v=e[i].v;
			nw[cnt].w=e[i].w;
			nw[cnt].id=0;
			fa[gf(e[i].u)]=gf(e[i].v);
		}
	}
	for(int i=0;i<k;++i){
		st[i]=rd();
		for(int j=1;j<=n;++j){
			a[i][j]=rd();
		}
	}
//	return 0;
	for(int i=0;i<k;++i){
		for(int j=1;j<=n;++j){
			nw[++cnt].u=n+i+1;
			nw[cnt].v=j;
			nw[cnt].w=a[i][j];
			nw[cnt].id=i+1;
		}
	}
	sort(nw+1,nw+cnt+1,cmp); 
	long long ans=1e18;
	for(int i=0;i<pw[k];++i){
		long long sum=0;
		flag[0]=1;
		for(int j=0;j<k;++j){
			if((i/pw[j])%2)sum+=st[j],flag[j+1]=1;
			else flag[j+1]=0;
		}
		for(int j=1;j<=n+10;++j)fa[j]=j,siz[j]=1;
		for(int j=1;j<=cnt;++j){
			if(flag[nw[j].id]){
				int fu=gf(nw[j].u),fv=gf(nw[j].v);	
				if(fu!=fv){
					if(siz[fu]>siz[fv])fa[fv]=fu,siz[fu]+=fv;
					else fa[fu]=fv,siz[fv]+=fu;
//					fa[fu]=fv;
					sum+=nw[j].w;
				}	
			}
		}
//		if(i<=10)cout<<i<<' '<<sum<<endl;
		ans=min(ans,sum);
	}
	wt(ans);
	return 0;
}

