# include <bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5 + 5;
int n,k;
int a[N];
bool k1=true,k10=true;
int jl = 0;
int ans = 0,da = 0;

unordered_map<int,int> pq;

struct se {
	int st,en;
};
se anlr[N];
int idx = 0;

bool cmp(se a,se b) {
	if (a.en != b.en) return a.en < b.en;
	if (a.st != b.st) return a.st < b.st;
	return true;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
		if (a[i] != 1) k1 = false;
		if (a[i] != 1 && a[i] != 0) k10 = false;
	}
	if (k1) {
		if (k == 0) cout << (n/2);
		else if (k == 1) cout << n;
		else cout << 0;
		return 0;
	}
	if (k10) {
		if (k == 1) {
			int cnt = 0;
			for (int i = 1;i <= n;i ++) {
				if (a[i] == 1) cnt ++;
			}
			cout << cnt;
			return 0;
		}
		if (k == 0) {
			int cnt = 0;
			bool l1 = false;
			for (int i = 1;i <= n;i ++) {
				if (l1) {
					l1 = false;
					cnt ++;
				}
				else {
					if (a[i] == 1) l1 = true;
					else cnt ++;
				}
			}
			cout << cnt;
			return 0;
		}
		cout << 0;
		return 0;
	}
	pq[jl^k] = 1;
	for (int i = 1;i <= n;i ++) {
		jl ^= a[i];
		if (pq.count(jl)) {
			se suc;
			suc.en = i;
			suc.st = pq[jl];
			idx ++;
			anlr[idx] = suc;
		}
		if (a[i] == k) {
			se succ;
			succ.st = i;
			succ.en = i;
			idx ++;
			anlr[idx] = succ;
		}
		pq[jl^k] = i+1;
	}
	//cout << idx << endl;
	sort(anlr+1,anlr+1+idx,cmp);
	/*for (int q = 1;q <= idx;q ++) {
		se p = anlr[q];
		cout << p.st << " " << p.en << endl;
	}*/
	for (int q = 1;q <= idx;q ++) {
		se p = anlr[q];
		if (p.st > da) {
			ans ++;
			da = p.en;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
