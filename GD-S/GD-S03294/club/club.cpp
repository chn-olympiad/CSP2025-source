#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define rep(i, j, k) for(int i = j; i <= k; i++)
#define ll long long 
#define rop(i, j, k) for(int i = j; i >= k; i--)
#define big __int128
#define ull unsigned ll 
#define mpr make_pair
using namespace std;
const int N = 1e5 + 5;
struct poi{
	int x, y, z, t;
}a[N];
bool cmp(poi x, poi y){return x.t > y.t;}
int res;
struct node{
	int id, val;
	bool operator < (const node &x) const{
		return val > x.val;
	}
};
priority_queue<node> q1, q2, q3;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _;
	cin >> _;
	while(_--){
		while(q1.size()) q1.pop();
		while(q2.size()) q2.pop();
		while(q3.size()) q3.pop();
		rep(i, 1, N - 3) a[i] = {0, 0, 0};
		//clean
		int n;
		cin >> n;
		rep(i, 1, n){
			int x, y, z;
			cin >> x >> y >> z;
			a[i] = {x, y, z, max(max(x, y), z)};
		} 
		sort(a + 1, a + n + 1, cmp);
		int res = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, lim = n >> 1;
		rep(i, 1, n){
			if(a[i].x == a[i].t) cnt1++, res += a[i].t, q1.push({i, min(a[i].t - a[i].y, a[i].t - a[i].z)});
			else if(a[i].y == a[i].t) cnt2++, res += a[i].t, q2.push({i, min(a[i].t - a[i].x, a[i].t - a[i].z)});
			else cnt3++, res += a[i].t, q3.push({i, min(a[i].t - a[i].x, a[i].t - a[i].y)});
		}
		while(cnt1 > lim || cnt2 > lim || cnt3 > lim){
			if(cnt1 > lim){
				cnt1--;
				node x = q1.top();	
				q1.pop();
				if(a[x.id].y > a[x.id].z) cnt2++, res -= x.val;
				else cnt3++, res -= x.val;
			}
			else if(cnt2 > lim){
				cnt2--;
				node x = q2.top();
				q2.pop();
				if(a[x.id].x > a[x.id].z) cnt1++, res -= x.val;
				else cnt3++, res -= x.val; 
			}
			else{
				cnt3--;
				node x = q3.top();
				q3.pop();
				if(a[x.id].x > a[x.id].y) cnt1++, res -= x.val;
				else cnt2++, res -= x.val; 
			}
		}
		cout << res << "\n";
	}
	return 0;	
} 
