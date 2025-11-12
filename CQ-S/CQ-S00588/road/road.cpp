#include <bits/stdc++.h>
using namespace std;

namespace Cherry {
	const int N=1e4+20,M=1e6+10;
	const long long INF=1e18;
	int n,m,k,cnt;
	long long ans;
	int c[15];
	
	struct stu {
		int x,id;
	}a[15][N];
	bool cmp0(stu a,stu b) { return a.x<b.x; }
	
	struct edge {
		int x,y,z;
	}es[M],e[N],ed[11*N],tmp[11*N];
	bool cmp(edge x,edge y) { return x.z<y.z; }
	
	int fa[N],siz[N];
	int find(int x) { return x==fa[x]?x:fa[x]=find(fa[x]); }
	
	void merge(int &now,int x,int y) {
		int i=1,j=1,k=0;
		while(i<=now&&j<=y) {
			if(ed[i].z<=a[x][j].x) tmp[++k]=ed[i++];
			else tmp[++k]=edge{x+n,a[x][j].id,a[x][j].x},j++;
		}
		while(i<=now) tmp[++k]=ed[i++];
		while(j<=y) tmp[++k]=edge{x+n,a[x][j].id,a[x][j].x},j++;
		now=k;
		for(int i=1;i<=now;i++) ed[i]=tmp[i];
	}
	
	long long solve1() {
		long long sum=0;
		for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
		sort(es+1,es+1+m,cmp);
		for(int i=1;i<=m;i++) {
			int fx=find(es[i].x),fy=find(es[i].y);
			if(fx!=fy) {
				if(siz[fx]<siz[fy]) swap(fx,fy);
				fa[fy]=fx,siz[fx]+=siz[fy];
				sum+=es[i].z;
				e[++cnt]=es[i];
				if(siz[fx]==n) break;
			}
		}
		return sum;
	}
	long long solve2(int S) {
		long long sum=0;
		for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=(i<=n);
		int now=0;
		for(int i=1;i<=cnt;i++) ed[++now]=e[i];
		for(int i=1;i<=k;i++) {
			if((S>>(i-1))&1) {
				sum+=c[i];
				if(sum>=ans) return sum;
				if(a[i][1].x>e[cnt].z) return INF;
			}
		}
		for(int i=1;i<=k;i++) {
			if((S>>(i-1))&1) {
				for(int j=1;j<=n+1;j++) {
					if(a[i][j].x>e[cnt].z||j>n) {
						merge(now,i,j-1);
						break;
					}
				}
			}
		}
		for(int i=1;i<=now;i++) {
			int fx=find(ed[i].x),fy=find(ed[i].y);
			if(fx!=fy) {
				if(siz[fx]<siz[fy]) swap(fx,fy);
				fa[fy]=fx,siz[fx]+=siz[fy];
				sum+=ed[i].z;
				if(siz[fx]==n||sum>=ans) return sum;
			}
		}
		return sum;
	}
	
	inline int read() {
		int ans=0; char ch='l';
		while(ch<'0'||ch>'9') ch=getchar();
		while(ch>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+ch-'0',ch=getchar();
		return ans;
	}
	
	int main() {
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++) es[i].x=read(),es[i].y=read(),es[i].z=read();
		for(int i=1;i<=k;i++) {
			c[i]=read();
			for(int j=1;j<=n;j++) a[i][j].x=read(),a[i][j].id=j;
			sort(a[i]+1,a[i]+1+n,cmp0);
		}
		ans=solve1();
		for(int S=1;S<(1<<k);S++) ans=min(ans,solve2(S));
		printf("%lld\n",ans);

		return 0;
	}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Cherry::main();
//	ÄÚ´æ:16MB 

	return 0;
}
/*
×¢Òâ¿ª long long!
*/
