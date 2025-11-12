#include<bits/stdc++.h>
#define N 11234
#define int long long
#define M 2123456 
using namespace std ;
int n , m , k , ans=LONG_LONG_MAX , f[N] , sz[N] , root[N] , cost[11][N] , tot1=0 , tot2=0 ;
struct road{
	int u , v , w ;
}a[M],bef[M];
bool cmp(road a,road b){
	return a.w<b.w ;
}
inline int find(int x){
	return f[x]==x?x:f[x]=find(f[x]) ;
}
inline void merge(int x,int y){
	x = find(x) , y = find(y) ;
	if(x==y) return ;
	if(sz[x]>sz[y]) swap(x,y) ;
	f[x] = y ;
	sz[y] += sz[x] ;
}
inline int read(){
	int x=0 ;
	char a=getchar() ;
	while(a<'0'||a>'9') a=getchar() ;
	while(a>='0'&&a<='9'){
		x *= 10 ;
		x += a-'0' ;
		a = getchar() ;
	}
	return x ;
}
signed main(){
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ;
	cin >> n >> m >> k ;
	for(int i=1;i<=m;i++){
		int u=read() , v=read() , w=read() ;
		bef[i] = road{u,v,w} ;
	}
	for(int i=1;i<=k;i++){
		root[i] = read() ;
		for(int j=1;j<=n;j++) cost[i][j] = read() ;
	}
	sort(bef+1,bef+1+m,cmp) ;
	for(int i=0,t=((1<<(k))-1),temp=0 ;i<=t;i++){
		tot1 = n , tot2 = temp = 0 ;
		for(int j=0;j<k;j++){
			if((1<<j)&i){
				tot1++ ;
				temp += root[j+1] ;
				for(int l=1;l<=n;l++) a[++tot2] = road{tot1,l,cost[j+1][l]} ;
			}
		}
		sort(a+1,a+1+tot2,cmp) ;
		for(int i=1;i<=tot1;i++) f[i]=i , sz[i]=1 ;
		road now ;
		for(int i=1,j=1;(i<=tot2||j<=m)&&ans>temp;){
			if(i>tot2||(j<=m&&bef[j].w<a[i].w)) now = bef[j++] ;
			else now = a[i++] ;
			if(find(now.u)!=find(now.v)) temp += now.w , merge(now.u,now.v) ;
		}	
		ans = min(ans,temp) ;
	}
	cout << ans ;
	return 0 ;
} 
