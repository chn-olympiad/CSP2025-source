#include <bits/stdc++.h>
#define LL long long
#define pr pair<int,int> 
#define add(u,v,w) g[u].push_back({v,w})
using namespace std ;
// T2
const int N=1e6+500 ;
LL n,m,k,c[N],s[15][N],fa[N],ans,us[N],rt ;
vector <pr> g[N] ;
struct eg {
	LL u,v,w ;
} a[N] ;  
LL bc (LL u) {
	if (fa[u]==u) return u ;
	return fa[u]=bc (fa[u]) ;
} 
bool cmp (eg a,eg b) {
	return a.w < b.w ;
}
void ksc () {
	LL s=0 ;
	for (LL i=1;i<=m;i++) {
		LL u=bc (a[i].u),v=bc (a[i].v) ;
		if (u!=v) {
			fa[u]=v ;
			if (a[i].w) 
			{
				if (a[i].u<=k*n && a[i].v<=k*n) s++ ;
				else {
					if (a[i].u>k*n) {
						if (!us[a[i].u-k*n]) {
							ans+=c[a[i].u-k*n] ;
							us[a[i].u-k*n]=1 ;
							s++ , n++ ;
						}
						else s++ ;
					}
					if (a[i].v>k*n) {
						if (!us[a[i].v-k*n]) {
							ans+=c[a[i].v-k*n] ;
							us[a[i].v-k*n]=1 ;
							s++ , n++ ;
						}
						else s++ ;
					}
				}
			} 
			ans+=a[i].w ;
		}
		if (s==n-1) break ;
	}
}  
void kscl () {
	sort (a+1,a+m+1,cmp) ;
	int s=0 ;
	for (LL i=1;i<=m;i++) {
		LL u=bc (a[i].u),v=bc (a[i].v) ;
		if (u!=v) {
			fa[u]=v ;s++ ; ans+=a[i].w ;
			add (a[i].u,a[i].v,a[i].w) ; add (a[i].v,a[i].u,a[i].w) ;
		}
		if (s==n-1) break ;
	}
}  
void Dian1 () {
	kscl () ;
	cout<<ans ;
}

int main () {
	freopen ("road.in","r",stdin) ;
	freopen ("road.out","w",stdout) ;
//	freopen ("hh","w",stdout) ;
	cin>>n>>m>>k ;
	if (!k) {
		for (LL i=1;i<=n;i++) fa[i]=i ;
		for (LL u,v,w,i=1;i<=m;i++) {
			cin>>u>>v>>w ;
			a[i].u=u,a[i].v=v,a[i].w=w ;
		}
		bool ky=1 ;
		for (LL i=1;i<=k;i++) {
			cin>>c[i] ;
			if (c[i]) ky=0 ;
			for (LL j=1;j<=n;j++) {
				cin>>s[i][j] ;
			}
		}
		if (k<=0) {
			Dian1 () ; return 0 ;
		}
		return 0 ;
	}
	for (LL i=1;i<=n*k+k;i++) fa[i]=i ;
	for (LL u,v,w,i=1;i<=m;i++) {
		cin>>u>>v>>w ;
		for (LL j=0;j<k;j++)
			a[i+j*n].u=u,a[i+j*n].v=v,a[i+j*n].w=w,m++ ;
	}
//	cout<<m<<"\n" ;
	for (LL i=1;i<=k;i++) {
		cin>>c[i] ;
		LL ss=0 ;
		for (LL j=1;j<=n;j++) {
			cin>>s[i][j] ;
			ss+=s[i][j] ;
		}
		if (c[i]>=ss) {
			c[i]=1e9 ;
			for (LL j=1;j<=n;j++) {
				s[i][j]=1e9 ;
			}
		}
	}
	m=k*n ;
	for (LL i=1;i<=k;i++) {
		LL t=k*n+i ;
		for (LL j=1;j<=n;j++) {
//			cout<<m<<"\n" ;
			a[++m]={t,(i-1)*n+j,s[i][j]} ;
			if (i<k) a[++m]={(i-1)*n+j,i*n+j,0} ;
		}
	}
	sort (a+1,a+m+1,cmp) ;
	ksc () ;
	cout<<ans ;
	return 0 ; 
}
