#include <iostream>
#include <vector>
#include <algorithm>

#define repm(i, begin, end) for (int i = begin; i < end; i += 1)
#define rep(i, n) repm(i, 0, n)
#define repi(i, begin, end) for (int i = begin; i <= end; i += 1)
#define rep1(i, n) repi(i, 1, n)

#define rrepi(i, begin, end) for (int i = end; i >= begin; i -= 1)

using namespace std;
using llu = long long unsigned;
using tp = unsigned short;

const bool debugm = true;

template<typename... Args>
void debug(const Args... arg) {
	if (debugm) {
		(int[]) {
			(void(cerr << arg << " "), 0)
			... 
		};
		
		cerr << endl;
	}
}

void set_io() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

struct hpns {
	tp a, b, c;
	
	void read() {
		cin >> a >> b >> c;
	}
	
	bool zero_bc() {
		return (b == 0 && c == 0);
	}
};

int main() {
	//set_io();
	
	int t;
	cin >> t;
	
	rep(_, t) {
		int n;
		cin >> n;
		
		const int hn = n / 2;
		vector<hpns> members(n);
		bool spec = true;
		
		rep(i, n) {
			members[i].read();
			spec &= members[i].zero_bc();
		}
		
		if (spec) {
			cout << "ok" << endl;
			sort(members.begin(), members.end(), [](hpns a, hpns b) {
				return a.a > b.a;
			});
			
			int sum = 0;
			rep(i, hn) {
				sum += members[i].a;
			}
			
			cout << sum << endl;
			continue;
		}
		
		
		vector<vector<int>> f(hn+1, vector<int>(hn+1, 0));
		int mx = -1;
		
		rep1(r, n) {
			int max_i = min(r, hn);
			
			rrepi(i, 0, max_i) {
				int min_j = max(r-hn-i, 0);
				int max_j = min(max_i, r-i);
				
				rrepi(j, min_j, max_j) {
					int k = r - i - j;
					
					int a = ((i == 0) ? 0 : (f[i-1][j] + members[r-1].a));
					int b = ((j == 0) ? 0 : (f[i][j-1] + members[r-1].b));
					int c = ((k == 0) ? 0 : (f[i][j] + members[r-1].c));
					
					f[i][j] = max({a, b, c});
					//debug(r, '{', i, j, k, '}', a, b, c, f[i][j]);
					if (r == n) mx = max(mx, f[i][j]);
				}
			}
		}
		
		cout << mx << endl;
	}
	
	return 0;
}
