#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct person{
	int a,b,c;
}a[N];
int n,sum;

int ans;
void dfs(int d,int cnta,int cntb,int cntc,int sum){
	if (cnta + cntb + cntc == n){
		ans = max(ans,sum);
		return ;
	}
	if (cnta < n / 2){
		dfs(d + 1,cnta + 1,cntb,cntc,sum + a[d].a);
	}
	if (cntb < n / 2){
		dfs(d + 1,cnta,cntb + 1,cntc,sum + a[d].b);
	}
	if (cntc < n / 2){
		dfs(d + 1,cnta,cntb,cntc + 1,sum + a[d].c);
	}
}

bool cmp(person b,person c){
	return b.a - b.b > c.a - c.b;
}
int main(int argc, char **argv){
#ifdef LOCAL
	bool isin,isout;
	cin >> isin >> isout;
	if (isin)
#endif
	freopen("club.in","r",stdin);
#ifdef LOCAL
	if (isout)
#endif
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	while (t--){
		ans = sum = 0;
		
		cin >> n;
		for (int i = 1;i <= n;i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
		}
		if (n <= 30){
			dfs(1,0,0,0,0);
			cout << ans;
			continue;
		}
		
		sort(a + 1,a + n + 1,cmp);
		for (int i = 1;i <= n / 2;i++){
			sum += a[i].a;
		}
		for (int i = n / 2 + 1;i <= n;i++){
			sum += a[i].b;
		}
		cout << sum << '\n';
	}
	return 0;
}

