#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct qq{
	
	int a,b,c,cn,maxx,minn,sum;
	
}d[N];

long long t,n,ans,cnt[5];

bool cmp (qq x,qq y) {
	return x.cn > y.cn;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	
	while (t --) {
		
		memset (cnt,0,sizeof(cnt));
		ans = 0;
		
		cin >> n;
		
		for (int i = 1;i <= n;i ++) {
			cin >> d[i].a >> d[i].b >> d[i].c;
			d[i].maxx = max (d[i].a,max(d[i].b,d[i].c));
			d[i].minn = min (d[i].a,min(d[i].b,d[i].c));
			d[i].sum = d[i].a + d[i].b + d[i].c;
			d[i].cn = d[i].maxx - (d[i].sum - d[i].maxx - d[i].minn);
	//		cout << d[i].cn << ' ';
		}
		
		sort (d + 1,d + n + 1,cmp);
		
		for (int i = 1;i <= n;i ++) {
			if (d[i].a == d[i].maxx && cnt[1] < n / 2) {
				ans += d[i].a;
				cnt[1] ++;
			} else if (d[i].b == d[i].maxx && cnt[2] < n / 2) {
				ans += d[i].b;
				cnt[2] ++;
			} else if (d[i].c == d[i].maxx && cnt[3] < n / 2) {
				ans += d[i].c;
				cnt[3] ++;
			} else if (d[i].a == d[i].maxx && d[i].b == d[i].sum - d[i].maxx - d[i].minn) {
				ans += d[i].b;
				cnt[2] ++;
			} else if (d[i].a == d[i].maxx && d[i].c == d[i].sum - d[i].maxx - d[i].minn) {
				ans += d[i].c;
				cnt[3] ++;
			} else if (d[i].b == d[i].maxx && d[i].a == d[i].sum - d[i].maxx - d[i].minn) {
				ans += d[i].a;
				cnt[1] ++;
			} else if (d[i].b == d[i].maxx && d[i].c == d[i].sum - d[i].maxx - d[i].minn) {
				ans += d[i].c;
				cnt[3] ++;
			} else if (d[i].c == d[i].maxx && d[i].a == d[i].sum - d[i].maxx - d[i].minn) {
				ans += d[i].a;
				cnt[1] ++;
			} else if (d[i].c == d[i].maxx && d[i].b == d[i].sum - d[i].maxx - d[i].minn) {
				ans += d[i].b;
				cnt[2] ++;
			}
			
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
