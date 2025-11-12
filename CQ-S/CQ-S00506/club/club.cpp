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

namespace akakakak{

	int t;
	int n;
	pr <long long, int> a[MAXN][3];
	int order[MAXN];
	int cnt[3];
	long long ans;
	int op;
	long long rem[MAXN];

	int main(){
		Read (t);
		while (t --> 0){
			Read (n);
			ans=0;
			cnt[0]=cnt[1]=cnt[2]=0;
			for (int i=1;i<=n;++i){
				Read (a[i][0].fst, a[i][1].fst, a[i][2].fst);
				a[i][0].scd=0; a[i][1].scd=1; a[i][2].scd=2;
				sort (a[i], a[i]+3, [](auto &x, auto &y){return x>y;});
				++cnt[a[i][0].scd];
				ans+=a[i][0].fst;
			}
			if (max({cnt[0], cnt[1], cnt[2]})<=(n>>1)) cout<<ans<<'\n';
			else{
				op=max({mkpr(cnt[0], 0), mkpr(cnt[1], 1), mkpr(cnt[2], 2)}).scd;
				rem[0]=0;
				for (int i=1;i<=n;++i) if (a[i][0].scd==op) rem[++rem[0]]=a[i][0].fst-a[i][1].fst;
				sort (rem+1, rem+rem[0]+1);
				for (int i=1;i<=cnt[op]-(n>>1);++i) ans-=rem[i];
				cout<<ans<<'\n';
			}

		}
		return 0;
	}
}

int main(){
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	return akakakak::main();
}
