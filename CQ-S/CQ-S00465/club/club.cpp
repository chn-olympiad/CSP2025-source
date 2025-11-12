#include<bits/stdc++.h>
const int QWQ=1e5+5;
using namespace std;
using LL=long long;
inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())
		if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
priority_queue<int,vector<int>,greater<int> > q[3];
struct dots{ int j,w; } a[QWQ][3]; int T,n,cc[3],ans;
inline void solve(){
	n=read(),ans=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<3;j++)
			a[i][j].w=read(),a[i][j].j=j;
		sort(a[i],a[i]+3,[&](dots x,dots y){
			return x.w>y.w;
		});
		cc[a[i][0].j]++,ans+=a[i][0].w;
		q[a[i][0].j].push(a[i][0].w-a[i][1].w);
	}
	int t=-1;
	for (int i:{0,1,2}) if (cc[i]>n/2) t=i;
	for (;~t&&cc[t]>n/2;)
		ans-=q[t].top(),cc[t]--,q[t].pop();
	printf("%d\n",ans);
	for (int i:{0,1,2}){
		cc[i]=0;
		for (;!q[i].empty();) q[i].pop();
	}
}
signed main(){
//	system("fc club.out club5.ans");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for (T=read();T--;) solve();
	return 0;
}
