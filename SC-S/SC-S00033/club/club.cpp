#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
#define pii std::pair<int,int>
#define mk std::make_pair
inline int read(){
	int x=0,f=1; char ch; ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isalnum(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline int max(int x,int y){
	if(x>y) return x;
	else return y;
}
inline int min(int x,int y){
	if(x<y) return x;
	return y;
}
const int maxn=1e5+10;
int T,n,a[maxn][4],limit,t[maxn],num[4];
pii pos[maxn][2];
inline bool cmp(int x,int y){
	return pos[x][0].first-pos[x][1].first>pos[y][0].first-pos[y][1].first;
}
inline void solve(){
	n=read(); limit=n>>1; int ans=0;
	for(int i=1;i<=3;++i) num[i]=0;
	for(int i=1;i<=n;++i) t[i]=i;
	for(int i=1;i<=n;++i) for(int j=1;j<=3;++j) a[i][j]=read();
	for(int i=1;i<=n;++i){
		if(a[i][1]>=a[i][2]){
			if(a[i][1]>=a[i][3]){
				pos[i][0]=mk(a[i][1],1);
				if(a[i][2]>=a[i][3]) pos[i][1]=mk(a[i][2],2);
				else pos[i][1]=mk(a[i][3],3);
			}
			else pos[i][0]=mk(a[i][3],3),pos[i][1]=mk(a[i][1],1);
		}
		else{
			if(a[i][2]>=a[i][3]){
				pos[i][0]=mk(a[i][2],2);
				if(a[i][1]>=a[i][3]) pos[i][1]=mk(a[i][1],1);
				else pos[i][1]=mk(a[i][3],3);
			}
			else pos[i][0]=mk(a[i][3],3),pos[i][1]=mk(a[i][2],2);
		}
	}
	std::stable_sort(t+1,t+1+n,cmp);
	for(int i=1;i<=n;++i){
		if(num[pos[t[i]][0].second]<limit) ans+=pos[t[i]][0].first,num[pos[t[i]][0].second]++;
		else ans+=pos[t[i]][1].first,num[pos[t[i]][1].second]++;
	}
	write(ans); puts("");
}
inline void work(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read(); while(T--) solve();
}
signed main(){work();return 0;}