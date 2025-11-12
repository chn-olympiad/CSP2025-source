/* ChongYun */
#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=1e5+5;
int T,n,ans[N];
struct Node{ int x,id; }a[N][3];
bool cmp(Node pt,Node qt){ return pt.x>qt.x; }
#define pii pair<int,int>
#define fir first
#define sec second
priority_queue<pii,vector<pii>,greater<pii> > q[3];
void solve(){
	for(int i=0;i<3;++i) while(!q[i].empty()) q[i].pop();
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=0;j<3;++j){
			a[i][j].x=read();
			a[i][j].id=j;
		}
		sort(a[i],a[i]+3,cmp);
		q[a[i][0].id].push({a[i][0].x-a[i][1].x,i});
		ans[i]=a[i][0].x;
	}	
	for(int i=0;i<3;++i){
		if(q[i].size()<=(n>>1)) continue;
		while(q[i].size()>(n>>1)){
			int x=q[i].top().sec;
			q[i].pop();
			q[a[x][1].id].push({a[x][1].id-a[x][2].id,i});
			ans[x]=a[x][1].x;
		}
	}
	int res=0;
	for(int i=1;i<=n;++i) res+=ans[i];
	printf("%lld\n",res);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) solve();
	return 0;
} 
