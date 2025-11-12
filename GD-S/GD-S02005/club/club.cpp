#include <bits/stdc++.h>
using namespace std;
#define int long long
int read(){ // 快读 
	int r = 0, w = 1;char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') w = -1;
		ch =getchar();
	} 
	while(isdigit(ch)){
		r = r * 10 + ch - '0';
		ch = getchar();
	}
	return r * w;
}
void solve(){
	int n;
	n = read();
	vector<int> a(n + 5), b(n + 5), c(n + 5), mx1(n + 5), mx2(n + 5);
	vector<pair<int, int> >d;
	for(int i = 1;i <= n;i++){
		a[i] = read(); b[i] = read(); c[i] = read();
		int maxn = max(a[i], max(b[i], c[i])), maxn2;
		if(a[i] == maxn) maxn2 = max(b[i], c[i]), mx1[i] = 0, mx2[i] = (b[i] > c[i] ? 1 : 2);
		else if(b[i] == maxn) maxn2 = max(a[i], c[i]), mx1[i] = 1, mx2[i] = (a[i] > c[i] ? 0 : 2);
		else if(c[i] == maxn) maxn2 = max(a[i], b[i]), mx1[i] = 2, mx2[i] = (a[i] > b[i] ? 0 : 1);
		d.push_back({maxn - maxn2, i});
	}  
	sort(d.begin(), d.end());
	int cnt[3] = {};
	int ans = 0;
	for(int i = n - 1;i >= 0;i--){
//		cout << d[i].second << '\n';
		int nowmax = mx1[d[i].second];
		int bei = mx2[d[i].second];
		if(cnt[nowmax] >= n / 2){
			cnt[bei]++;
			if(bei == 0) ans += a[d[i].second];
			else if(bei == 1) ans += b[d[i].second];
			else if(bei == 2) ans += c[d[i].second]; 
		} else {
			cnt[nowmax]++;
			if(nowmax == 0) ans += a[d[i].second];
			else if(nowmax == 1) ans += b[d[i].second];
			else if(nowmax == 2) ans += c[d[i].second]; 
		}
	}
	/*
	考虑贪心，我们思考一下如果一个人的A部门是最大的，我们可以发现如果这样，
	将所有最大的放在一个部门是最好的
	我们同时思考如果把他放到别处会不会更优，由于放到别处，若他的另一个部门的值相较于现在会减小
	但可以多一个新的人加入此部门，我们发现 如果这个人的值足以保证加入本部门比加入另一个人加入另一个部门
	减少的量不变，我们可以考虑将他加入本部门
	或许先处理较小的比较好，我们思考，如果将较小的放入它最大的部门，也不行，也会出现上面的情况
	我们对其他部门都是 0 的部分分进行分析，可以发现我们只需要将有的部门排序，选择前 n/2 个
	继续考虑有一个部门全是 0 的情况，我们发现选择哪个部门可以利用 
	
	或许还有一种做法，我们统计每一个人的最大满意度和最小满意度之差，可以得到我们一个部门的权值
	排序，然后再按从大到小的顺序便利，加入部门 
	*/
	cout << ans << '\n';
}
signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	t = read();
	while(t--)solve();
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
