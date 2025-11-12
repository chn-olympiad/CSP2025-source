#include<bits/stdc++.h> 
#define int long long 
#define x first 
#define y second 
#define il inline 
#define eb emplace_back 
#define debug() puts("-----") 
using namespace std; 
typedef pair<int,int> pii; 
il int read(){ 
	int x=0,f=1; char ch=getchar(); 
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } 
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar(); 
	return x*f; 
} 
const int N=1e5+10; 
int n; 
pii p[N]; 
il bool cmp(pii a,pii b){ 
	return a.x>b.x; 
} 
il void solve(){ 
	n=read(); int res=0; 
	int cnt[3]={0,0,0}; 
	for(int i=1;i<=n;i++){ 
		pii t[3]; for(int j=0;j<3;j++) t[j].x=read(),t[j].y=j; 
		sort(t,t+3,cmp); res+=t[0].x; 
		p[i]={t[0].x-t[1].x,t[0].y}; 
	} sort(p+1,p+n+1,cmp); 
	for(int i=1;i<=n;i++){ 
		if(cnt[p[i].y]<n/2) cnt[p[i].y]++; 
		else res-=p[i].x; 
	} printf("%lld\n",res); 
} 
signed main(){ 
//	if(system("fc ans.ans club5.ans")) puts("WA"); 
//	else puts("AC"); return 0; 
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
	int T=read(); 
	while(T--) solve(); 
	return 0; 
} /*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
