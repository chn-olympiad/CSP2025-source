#include<bits/stdc++.h>
#define LL long long
#define Un unsigned
#define For1(i,a,b) for(i=(a);i<=(b);++i)
#define For2(i,a,b) for(i=(a);i<(b);++i)
#define FoR1(i,a,b) for(i=(a);i>=(b);--i)
#define FoR2(i,a,b) for(i=(a);i>(b);--i)
#define pii std::pair<int,int>
#define mkp std::make_pair
#define pb emplace_back
#define il inline
#define fir first
#define sec second
#define dbg(x...) (fprintf(stderr,x),fflush(stderr))
#define FI using std::cin;std::ios::sync_with_stdio(0),cin.tie(0)
template<class T1>
il void cmin(T1 &x,T1 y){if(x>y)x=y;}
template<class T1>
il void cmax(T1 &x,T1 y){if(x<y)x=y;}
const int N=100111;
int a[N][3],b[N],c[N],n,k,T;
signed main(){FI;int i,j;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		For1(i,1,n){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			b[i]=0;
			For1(j,1,2)if(a[i][j]>a[i][b[i]])b[i]=j;
		}
		int cnt[3]={0};
		For1(i,1,n)++cnt[b[i]];
		k=0;
		For1(j,1,2)if(cnt[j]>cnt[k])k=j;
		LL ans=0ll;
		if(cnt[k]<=(n>>1)){
			For1(i,1,n)ans+=a[i][b[i]];
			printf("%lld\n",ans);
			continue;
		}
		For1(i,1,n){
			c[i]=0;
			For1(j,0,2)if(j!=k)cmax(c[i],a[i][j]);
			ans+=c[i];
			c[i]=a[i][k]-c[i];
		}
		std::sort(c+1,c+n+1);
		For1(i,(n>>1)+1,n)ans+=c[i];
		printf("%lld\n",ans);
	}
	return 0;
}