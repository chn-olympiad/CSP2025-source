#include<bits/stdc++.h>
#define N 112345
using namespace std ;
int T , n , cmx1 , cmx2 , cmx3 , ans , tot=0 ;
bool used[N] ;
struct node1{
	int a , b , c , mx , i ;
}a[N];
struct node2{
	int w , i ;
}b[N];
bool cmp1(node2 a,node2 b){
	return a.w<b.w ;
}
signed main(){
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
	cin >> T ;
	while(T--){
		cmx1 = cmx2 = cmx3 = ans = tot = 0 ;
		scanf("%d",&n) ;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c) , a[i].i=i , a[i].mx = max(max(a[i].a,a[i].b),a[i].c) , used[i]=0 ;
		for(int i=1;i<=n;i++){
			ans += a[i].mx ;
			if(a[i].a==a[i].mx) cmx1++ ;
			else if(a[i].b==a[i].mx) cmx2++ ;
			else if(a[i].c==a[i].mx) cmx3++ ;
		}
		if(cmx1>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].a==a[i].mx){
					b[++tot] = node2{a[i].mx-a[i].b,a[i].i} ;
					b[++tot] = node2{a[i].mx-a[i].c,a[i].i} ;
				}
			}
		}else if(cmx2>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].b==a[i].mx){
					b[++tot] = node2{a[i].mx-a[i].a,a[i].i} ;
					b[++tot] = node2{a[i].mx-a[i].c,a[i].i} ;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i].c==a[i].mx){
					b[++tot] = node2{a[i].mx-a[i].a,a[i].i} ;
					b[++tot] = node2{a[i].mx-a[i].b,a[i].i} ;
				}
			}
		}
		cmx1 = max(max(cmx1,cmx2),cmx3) ;
		sort(b+1,b+1+tot,cmp1) ;
		for(int i=1;i<=tot&&cmx1>n/2;i++) if(!used[b[i].i]) ans -= b[i].w , used[b[i].i]=1 , cmx1-- ;
		printf("%d\n",ans) ;
	}
	return 0 ;
} 
