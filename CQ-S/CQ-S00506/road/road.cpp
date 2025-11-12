#include <bits/stdc++.h>
using namespace std;

char buf[1<<21];
char* p1;
char* p2;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf, 1, 1<<21, stdin), p1==p2)?EOF:*p1++)

template <typename T>
inline void Read(T &in){
	in=0;
	bool tag=0;
	char ch=0;
	while (ch=getchar(), !isdigit(ch) && ch!=EOF) if (ch=='-') tag=1;
	if (ch==EOF) return;
	while (isdigit(ch)) in=(in<<1)+(in<<3)+ch-48, ch=getchar();
	if (tag) in=-in;
	return;
}

template <typename T, typename ...Args>
inline void Read(T &in, Args &...rest){
	return Read(in), Read(rest...);
}

#define pr pair
#define fst first
#define scd second
#define mkpr make_pair
#define MAXN 200005
#define MAXINK 15
#define MAXM 2000005

namespace akakakak{

	int n, m, ink;

	pr <long long, pr<int, int>> ines[MAXM];
	int cnt;
	long long inc[MAXN];
	pr <long long, int> ina[MAXINK][MAXN];

	int belong[MAXN];
	inline int Belong(int u){
		if (u==belong[u]) return u;
		return belong[u]=Belong(belong[u]);
	}
	
	long long ans;
	using type=pr<pr<long long, int>, pr<int, int>>;
	priority_queue <type, vector<type>, greater<type>> q;
	int link[MAXINK];

	int main(){
		Read (n, m, ink);
		for (int i=1;i<=m;++i) Read (ines[i].scd.fst, ines[i].scd.scd, ines[i].fst);
		sort (ines+1, ines+m+1);
		for (int i=1;i<=ink;++i){
			Read (inc[i]);
			for (int j=1;j<=n;++j){
				Read (ina[i][j].fst);
				ina[i][j].scd=j;
			}
			sort (ina[i]+1, ina[i]+n+1);
		}
		for (int i=1;i<=n;++i) belong[i]=i;
		for (int i=1;i<=m;++i) if (Belong(ines[i].scd.fst)!=Belong(ines[i].scd.scd)){
			ines[++cnt]=ines[i];
			ans+=ines[i].fst;
			belong[belong[ines[i].scd.fst]]=belong[ines[i].scd.scd];
			if (cnt==n-1) break;
		}
		for (int s=1;s<(1<<ink);++s){
			long long res=0;
			while (q.size()) q.pop ();
			q.emplace (mkpr(ines[1].fst, 0), mkpr(ines[1].scd.fst, ines[1].scd.scd));
			for (int i=1;i<=n+ink;++i) belong[i]=i;
			for (int i=0;i<=ink;++i) link[i]=1;
			int got=0;
			for (int i=1;i<=ink;++i) if ((s>>(i-1))&1){
				res+=inc[i];
				++got;
				q.emplace (mkpr(ina[i][1].fst, i), mkpr(n+i, ina[i][1].scd));
			}
			if (res>=ans) continue;
			int count=0;
			while (q.size() && count<n+got-1){
				auto u=q.top(); q.pop ();
				if (u.fst.scd){
					if (link[u.fst.scd]<n){
						++link[u.fst.scd];
						q.emplace (mkpr(ina[u.fst.scd][link[u.fst.scd]].fst, u.fst.scd), mkpr(n+u.fst.scd, ina[u.fst.scd][link[u.fst.scd]].scd));
					}
				}
				else{
					if (link[0]<cnt){
						++link[0];
						q.emplace (mkpr(ines[link[0]].fst, 0), mkpr(ines[link[0]].scd.fst, ines[link[0]].scd.scd));
					}
				}
				if (Belong(u.scd.fst)==Belong(u.scd.scd)) continue;
				++count;
				res+=u.fst.fst;
				if (res>=ans) break;
				belong[belong[u.scd.fst]]=belong[u.scd.scd];
			}
			ans=min(ans, res);
		}
		cout<<ans<<'\n';
		return 0;
	}
}

int main(){
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	return akakakak::main();
}
