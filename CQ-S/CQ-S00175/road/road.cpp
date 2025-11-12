#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
using namespace std;
const int N=1e4+10+5,M=1e6+5;
char Ch;
int ff;
void rd(int &x) {
	x=0,ff=1;
	Ch=getchar();
	while((Ch<'0' || Ch>'9') && Ch!='-') Ch=getchar();
	if(Ch=='-') ff=-1,Ch=getchar();
	while(Ch>='0' && Ch<='9') {
		x=(x<<1)+(x<<3)+Ch-'0';
		Ch=getchar();
	}
	x*=ff;
}
vector<tuple<int,int,int>> e,old,v; 
int n,m,k;
int c[N];
int fa[N],prt[N],val[N];
int a[11][N];
ll ans=1e18,os,sum;
int q[N];
int getfa(int x) {
	if(x==fa[x]) return x;
	return fa[x]=getfa(fa[x]);
}
int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	rd(n),rd(m),rd(k);
	for(int i=1,x,y,z; i<=m; i++) {
		rd(x),rd(y),rd(z);
		e.pb(z,x,y);
	}
	sort(e.begin(),e.end());
	for(int i=1; i<=n; i++) fa[i]=i;
	for(auto it:e) {
		int w=get<0>(it),x=get<1>(it),y=get<2>(it);
		int fx=getfa(x),fy=getfa(y);
		if(fa[fx]!=fa[fy]) {
			fa[fx]=fy;
			os+=w;
			old.pb(w,x,y);
		}
	}
//	cout<<"Old tree\n";
//	for(int i=1; i<=n; i++)
//		for(auto it:old[i])
//			printf("%d %d %d\n",i,it.first,it.second);
//	cout<<'\n';
	for(int i=1; i<=k; i++) {
		rd(c[i]);
		for(int j=1; j<=n; j++)
			rd(a[i][j]);	
	}
	for(int sta=0; sta<(1<<k); sta++) {
		sum=0;
		v=old;
		for(int i=1; i<=n+k; i++)
			fa[i]=i;
		for(int i=1; i<=k; i++)
			if(sta>>(i-1)&1) {
				sum+=c[i];
				for(int j=1; j<=n; j++)
					v.pb(a[i][j],i+n,j);
			}
		sort(v.begin(),v.end());
		for(auto it:v) {
			int w=get<0>(it),x=get<1>(it),y=get<2>(it);
			int fx=getfa(x),fy=getfa(y);
			if(fa[fx]!=fa[fy]) {
				fa[fx]=fy;
				sum+=w;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
/*
如果打通了一点而结果不和1~n联通一定不优 
O(n*n)暴力跳树 
1 5 1
2 4 5
2 5 5
3 4 4
4 2 5
4 1 6
5 1 1
5 2 5
*/
