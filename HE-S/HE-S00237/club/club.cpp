#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=2e5+10;
inline int read() {
	int s=0,x=1;char ch=getchar();
	while(ch<'0'||ch>'9') x=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*x;
}
int n,a[N][4],nd[4],stk[4][N],ans;
inline bool cmp1(int x,int y) {
	return min(a[x][1]-a[x][2],a[x][1]-a[x][3])<min(a[y][1]-a[y][2],a[y][1]-a[y][3]);
}
inline bool cmp2(int x,int y) {
	return min(a[x][2]-a[x][1],a[x][2]-a[x][3])<min(a[y][2]-a[y][1],a[y][2]-a[y][3]);
}
inline bool cmp3(int x,int y) {
	return min(a[x][3]-a[x][1],a[x][3]-a[x][2])<min(a[y][3]-a[y][1],a[y][3]-a[y][2]);
}
inline void calc(int pos) {for(int i=1;i<=nd[pos];++i) ans+=a[stk[pos][i]][pos];}
inline void work(int pos) {
	if(pos==1) sort(stk[1]+1,stk[1]+nd[1]+1,cmp1);
	else if(pos==2) sort(stk[2]+1,stk[2]+nd[2]+1,cmp2);
	else sort(stk[3]+1,stk[3]+nd[3]+1,cmp3);
	for(int i=1;i<=nd[pos]-n/2;++i) {
		if(pos==1) {
			if(a[stk[1][i]][2]<a[stk[1][i]][3]) ans+=a[stk[1][i]][3];
			else ans+=a[stk[1][i]][2];
		}
		else if(pos==2) {
			if(a[stk[2][i]][1]<a[stk[2][i]][3]) ans+=a[stk[2][i]][3];
			else ans+=a[stk[2][i]][1];
		}
		else {
			if(a[stk[3][i]][1]<a[stk[3][i]][2]) ans+=a[stk[3][i]][2];
			else ans+=a[stk[3][i]][1];
		}
	}
	for(int i=nd[pos]-n/2+1;i<=nd[pos];++i) ans+=a[stk[pos][i]][pos];
}
inline void solve() {
	n=read();nd[1]=nd[2]=nd[3]=0;ans=0;
	for(int i=1,ch;i<=n;++i) {
		a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		ch=1;if(a[i][2]>a[i][ch]) ch=2;
		if(a[i][3]>a[i][ch]) ch=3;
		stk[ch][++nd[ch]]=i;
	}
	for(int i=1;i<=3;++i) {
		if(nd[i]<=n/2) calc(i);
		else work(i);
	}
	printf("%d\n",ans);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();while(T--) solve();
	return 0;
}
