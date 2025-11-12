#include<iostream>
#include<algorithm>
#define int long long
#define endl '\n'
using namespace std;
const int N = 110;
int n,m,a[N];
bool cmp(int x,int y){
	return x > y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int x = a[1],id = 0;
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == x){
			id = i;
		}
	}
	int cnt = id / n;
	int sum = id - cnt * n;
	if(cnt % 2 == 0){
		if(sum > 0){
			cout << cnt + 1 << ' ' << sum;
		} else {
			cout << cnt << ' ' << 1;
		}
	} else {
		if(sum > 0){
			cout << cnt + 1 << ' ' << n - sum + 1;
		} else {
			cout << cnt << ' ' << n;
		}
	}
	return 0;
}
