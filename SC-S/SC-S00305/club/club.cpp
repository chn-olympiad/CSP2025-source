#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, x, y, z, sum;
int arr[100005][5];
struct kode{
	int bh, flag;
	bool operator <(const kode &x) const{
		if(flag == 1){
			return min(arr[x.bh][1] - arr[x.bh][2], arr[x.bh][1] - arr[x.bh][3]) < min(arr[bh][1] - arr[bh][2], arr[bh][1] - arr[bh][3]);
		}
		if(flag == 2){
			return min(arr[x.bh][2] - arr[x.bh][1], arr[x.bh][2] - arr[x.bh][3]) < min(arr[bh][2] - arr[bh][1], arr[bh][2] - arr[bh][3]);
		}
		if(flag == 3){
			return min(arr[x.bh][3] - arr[x.bh][2], arr[x.bh][3] - arr[x.bh][1]) < min(arr[bh][3] - arr[bh][2], arr[bh][3] - arr[bh][1]);
		}
	}
};
priority_queue <kode> a;
priority_queue <kode> b;
priority_queue <kode> c;
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(int T = 1; T <= t; T++){
		cin >> n;
		sum = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d %d %d", &x, &y, &z);
			arr[i][1] = x;arr[i][2] = y;arr[i][3] = z;
		}
		for(int i = 1; i <= n; i++){
			int ya = arr[i][1], yb = arr[i][2], yc = arr[i][3], ba, bb, bc;
			if(a.size()){
				ba = a.top().bh;
			}
			if(b.size()){
				bb = b.top().bh;
			}
			if(c.size()){
				bc = c.top().bh;
			}
			if(a.size() == n / 2){
				ya = ya - min(arr[ba][1] - arr[ba][2], arr[ba][1] - arr[ba][3]);
			}
			if(b.size() == n / 2){
				yb = yb - min(arr[bb][2] - arr[bb][1], arr[bb][2] - arr[bb][3]);
			}
			if(c.size() == n / 2){
				yc = yc - min(arr[bc][3] - arr[bc][1], arr[bc][3] - arr[bc][2]);
			}
			int k = max(ya, max(yb, yc));
			if(k == ya){
				if(a.size() == n / 2){
					a.pop();
					if(arr[ba][1] - arr[ba][2] <= arr[ba][1] - arr[ba][3]){
						b.push({ba, 2});
					}
					else{
						c.push({ba, 3});
					}
				}
				a.push({i, 1});
				continue;
			}
			if(k == yb){
				if(b.size() == n / 2){
					b.pop();
					if(arr[bb][2] - arr[bb][1] <= arr[bb][2] - arr[bb][3]){
						a.push({bb, 1});
					}
					else{
						c.push({bb, 3});
					}
				}
				b.push({i, 2});
				continue;
			}
			if(k == yc){
				if(c.size() == n / 2){
					c.pop();
					if(arr[bc][3] - arr[bc][2] <= arr[bc][3] - arr[bc][1]){
						b.push({bc, 2});
					}
					else{
						a.push({bc, 1});
					}
				}
				c.push({i, 3});
				continue;
			}
		}
		while(a.size()){
			sum = sum + arr[a.top().bh][1];
			a.pop();
		}
		while(b.size()){
			sum = sum + arr[b.top().bh][2];
			b.pop();
		}
		while(c.size()){
			sum = sum + arr[c.top().bh][3];
			c.pop();
		}
		cout << sum << endl;
	}
	return 0;
}
