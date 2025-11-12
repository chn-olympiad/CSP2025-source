#include<bits/stdc++.h>
using namespace std;

struct Node{
	int x, y, z;
	int fl;
	int MX(){
		return max(max(x, y), z);
	}
	int X(){
		int p[3];
		p[0] = x, p[1] = y, p[2] = z;
		sort(p, p+3);
		return p[2] - p[1];
	}
}a[100005];

int n;
int ans;

bool cmp(Node L, Node R){
	return L.X() < R.X();
}

void Main(){
	ans = 0;
	cin >> n;
	int cnt1, cnt2, cnt3;
	cnt1=cnt2=cnt3=0;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
		ans += a[i].MX();
		//cout << ans << endl;
		if(a[i].MX() == a[i].x) cnt1++, a[i].fl = 1;
		else if(a[i].MX() == a[i].y) cnt2++, a[i].fl = 2;
		else if(a[i].MX() == a[i].z) cnt3++, a[i].fl = 3;
	}
	//cout << "cnt" << cnt1 << ' ' << cnt2 << ' ' << cnt3 << endl;
	sort(a+1, a+n+1, cmp);
	int i = 1;
	if(cnt1 > n/2){
		while(cnt1 > n/2){
			if(a[i].fl != 1) {
				i++;
				continue;
			}
			//cout << a[i].x <<' '<< a[i].y <<' '<< a[i].z << endl;
			ans -= a[i].X();
			cnt1--;
			i++;
			//cout << ans << endl;
		}
	}
	else if(cnt2 > n/2){
		while(cnt2 > n/2){
			if(a[i].fl != 2) {
				i++;
				continue;
			}
			//cout << a[i].x <<' '<< a[i].y <<' '<< a[i].z << endl;
			ans -= a[i].X();
			cnt2--;
			i++;
			//cout << ans << endl;
		}
	}
	else if(cnt3 > n/2){
		while(cnt3 > n/2){
			if(a[i].fl != 3) {
				i++;
				continue;
			}
			//cout << a[i].x <<' '<< a[i].y <<' '<< a[i].z << endl;
			ans -= a[i].X();
			cnt3--;
			i++;
			//cout << ans << endl;
		}
	}
	cout << ans << endl;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}
