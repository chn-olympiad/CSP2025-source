#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 7;
int n, cnt[5];
ll ans;

struct Node{
	int num1, id1, num2, id2;
	bool operator<(const Node & no)const{
		return num1 > no.num1;
	}
}a[5], b[N];

bool cmp(Node x, Node y){
	return x.num1 - x.num2 > y.num1 - y.num2;
}

int main(){
	ios::sync_with_stdio(false);
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
	int T; cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; ++i){
			cin >> a[1].num1 >> a[2].num1 >> a[3].num1; a[1].id1 = 1; a[2].id1 = 2; a[3].id1 = 3;
			sort(a + 1, a + 4);
			b[i].num1 = a[1].num1; b[i].id1 = a[1].id1; b[i].num2 = a[2].num1; b[i].id2 = a[2].id1;
		}
		sort(b + 1, b + n + 1, cmp); ans = 0; cnt[1] = cnt[2] = cnt[3] = 0;
		for(int i = 1; i <= n; ++i){
			if(cnt[b[i].id1] >= n / 2){
				cnt[b[i].id2]++;
				ans += b[i].num2;
			}else{
				cnt[b[i].id1]++;
				ans += b[i].num1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}