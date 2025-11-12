#include<bits/stdc++.h>
using namespace std;
int fa[20005],xfa[20005],n,m,k,ycnt,cnt,cb,fan,a[15],b[2000][15],size[2000];
long long ans;
int find(int x) {
	return fa[x]==x?x:find(fa[x]);
}
int xfind(int x) {
	return xfa[x]==x?x:xfind(xfa[x]);
}
struct road {
	int u,v,w;
} e[2000006],nd[2000006],ynd[2000006];
struct contre {
	int bw,a[10005];
} ct[15];
int cmp(road x,road y) {
	return x.w<y.w;
}
int ccmp(contre x,contre y) {
	return x.bw<y.bw;
}
void dfs(int x,int y,int z) {
	if(x>k) {
		if(z!=0) {
			fan++;
			size[fan]=z;
			for(int i=1; i<=z; i++)b[fan][i]=a[i];
		}
		return;
	}
	if(y+ct[x].bw<ans) {
		a[z+1]=x;
		dfs(x+1,y+ct[x].bw,z+1);
	}
	dfs(x+1,y,z);
}
long long chk(int metho,road xe[],int xn,int xm,int xcb) {
	for(int i=1; i<=n; i++)xfa[i]=i;
	long long res=0;
	for(int i=1; i<=size[metho]; i++) {
		xcb++;
		int nw=b[metho][i];
		res+=ct[nw].bw;if(res>ans)return 1e18;
		for(int j=xm+1; j<=xm+xn; j++) {
			xe[j].u=j-xm;
			xe[j].v=xn+xcb;
			xe[j].w=ct[nw].a[j-xm];
		}
		xm+=xn;
	}
	sort(xe+1,xe+xm+1,cmp);
	for(int i=1; i<=xm; i++) {
		int q=xe[i].u,p=xe[i].v;
		q=xfind(q);
		p=xfind(p);
		if(p!=q) {
			xfa[p]=q;
			res+=xe[i].w;
			if(res>ans)return 1e18;
		}
	}
	return res;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)fa[i]=i;
	for(int i=1; i<=m; i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1; i<=k; i++) {
		cin>>ct[i].bw;
		for(int j=1; j<=n; j++)cin>>ct[i].a[j];
		if(ct[i].bw==0) {
			cb++;
			for(int j=m+1; j<=m+n; j++) {
				e[j].u=j-m;
				e[j].v=n+cb;
				e[j].w=ct[i].a[j-m];
			}
			m+=n;
			i--;
			k--;
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1; i<=m; i++) {
		int q=e[i].u,p=e[i].v;
		q=find(q);
		p=find(p);
		if(p!=q) {
			fa[p]=q;
			ans+=e[i].w;
			ynd[++ycnt].u=nd[++cnt].u=e[i].u;
			ynd[ycnt].v=nd[cnt].v=e[i].v;
			ynd[ycnt].w=nd[cnt].w=e[i].w;
		}
	}
	if(k==0) {
		cout<<ans;
		return 0;
	}
	sort(ct+1,ct+k+1,ccmp);
	dfs(1,0,0);
	for(int i=1; i<=fan; i++)ans=min(ans,chk(i,nd,n,m,cb));
	cout<<ans;
	return 0;
}
