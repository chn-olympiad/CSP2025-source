#include <bits/stdc++.h>
#define re register
#define fst first
#define snd second
#define int long long
#define chmax(a,b) (a = max(a,b))

using namespace std;

typedef pair<int,int> pii;
const int N = 1e5 + 10;
int n;
int arr[N][3],cnt[3];

inline int read(){
	int r = 0,w = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		r = (r << 1) + (r << 3) + (c ^ 48);
		c = getchar();
	}
	return r * w;
}

inline void solve(){
	int ans = 0;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	memset(cnt,0,sizeof(cnt));
	n = read();
	for (re int i = 1;i <= n;i++){
		for (re int j = 0;j < 3;j++) arr[i][j] = read();
	}
	for (re int i = 1;i <= n;i++){
		int Max = -1,Mid = -1;
		int cMax = -1,cMid = -1;
		for (re int j = 0;j < 3;j++){
			if (arr[i][j] > Max){
				cMax = Max,cMid = Mid;
				Max = arr[i][Mid = j];
			}
			else if (arr[i][j] > cMax) cMax = arr[i][cMid = j];
		} ans += Max; cnt[Mid]++;
		q.push({Max - cMax,Mid});
	} int tmp = 0,tid = 0;
	for (re int i = 0;i < 3;i++){
		if (cnt[i] > tmp) tmp = cnt[tid = i];
	} tmp = max(0ll,tmp - n / 2);
	while (tmp--){
		while (!q.empty() && q.top().snd != tid) q.pop();
		ans -= q.top().fst; q.pop();
	} printf("%lld\n",ans);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T = read();
	while (T--) solve();
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
