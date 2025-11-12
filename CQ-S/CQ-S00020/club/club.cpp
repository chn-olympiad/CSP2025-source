#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0;bool f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f^=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int Maxn=1e5+5;
int n;
int a[Maxn][5],id[Maxn][5];
int cnt[5];
vector<int>b[5];
inline void solve(){
	n=read();
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=3;i++)b[i].clear();
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)a[i][j]=read();
		int idd=0;
		if(a[i][1]==max({a[i][1],a[i][2],a[i][3]}))cnt[1]++,idd=1;
		else if(a[i][2]==max({a[i][1],a[i][2],a[i][3]}))cnt[2]++,idd=2;
		else if(a[i][3]==max({a[i][1],a[i][2],a[i][3]}))cnt[3]++,idd=3;
		ans+=max({a[i][1],a[i][2],a[i][3]});
		
		int mx=0,mx1=0;
		for(int j=1;j<=3;j++){
			if(a[i][j]>=mx)mx1=mx,mx=a[i][j];
			else mx1=max(mx1,a[i][j]);
		}b[idd].push_back(mx-mx1);
	}
	int tp=max(0ll,max({cnt[1],cnt[2],cnt[3]})-n/2),idd=0;
	for(int i=1;i<=3;i++)if(cnt[idd]<=cnt[i])idd=i;
	sort(b[idd].begin(),b[idd].end());
	for(int i=0;i<tp;i++)ans-=b[idd][i];
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)solve();
	return 0;
}
/*
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
