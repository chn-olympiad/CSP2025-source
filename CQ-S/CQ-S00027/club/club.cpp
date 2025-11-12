#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define db double
#define fi first
#define se second
#define MP make_pair
#define pb push_back
#define low lower_bound
#define upp upper_bound
using namespace std;
namespace hwq{
	inline int read(){int x=0;bool f=0;char ch=getchar();while(!isdigit(ch)&&ch!='-') ch=getchar();if(ch=='-') f=1,ch=getchar();while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-48,ch=getchar();return f?-x:x;}
	random_device R;
	mt19937 G(R());
	inline ll rd(ll l,ll r){return uniform_int_distribution<ll>(1ll,1ll<<62)(G);}
	const int MAXN=1e5+5;
	int n;
	int a[MAXN][5]; 
	int d[MAXN],siz[5];
	bool vis[MAXN];
	#define Pair pair<int,int>
	std::priority_queue<Pair>pq[5];
	int main(){
		for(int time=read();time--;){
			for(int i=1;i<=n;i++) vis[i]=0;
			for(int i=0;i<3;i++) siz[i]=0;
			for(int i=0;i<3;i++) while(!pq[i].empty()) pq[i].pop();
			n=read();
			for(int i=1;i<=n;i++) for(int j=0;j<3;j++) a[i][j]=read();
			int ans=0;
			for(int i=1;i<=n;i++){
				int mx=0;
				for(int j=1;j<3;j++) if(a[i][j]>a[i][mx]) mx=j;
				siz[mx]++,ans+=a[i][mx];
				for(int j=0;j<3;j++) if(mx^j) pq[mx].push(MP(a[i][j]-a[i][mx],i));
			}
			int mx=0;
			for(int i=1;i<3;i++) if(siz[i]>siz[mx]) mx=i;
			while(siz[mx]>(n>>1)){
				while(vis[pq[mx].top().se]) pq[mx].pop();
				ans+=pq[mx].top().fi,vis[pq[mx].top().se]=1,pq[mx].pop(),siz[mx]--;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
}
int main(){
//	while(1) //3
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	hwq::main();
	return 0;
}
/*
红温键盘 
感觉有点小难，带悔贪心？？？
对于每个人，先选择其贡献最大的分组
再去调整，d1->d2调整贡献即为最小的a(i,2)-a(i,1) 
最大的集合调整到另外两个集合，结束后一定合法 
拿下！ 
*/
