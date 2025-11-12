#include <bits/stdc++.h>
using namespace std;
int a[500005];
int dp[500005];
struct Node{
	int x,y;
}q[500005];
int Xor(int x,int y){
	int t[50005];
	int tt = 1;
	while(x != 0 || y != 0){
		t[tt] = (x + y) % 2;
		tt++;
		x /= 2;
		y /= 2;
	}
	int sum = 0;
	tt--;
	for(int i = tt;i >= 1;i--) sum = sum * 2 + t[i];
	return sum;
}
bool cmp(Node o,Node p){
	if(o.y != p.y) return o.y < p.y;
	else if(o.x != p.x) return o.x < p.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	int k;
	cin >> n >> k;
	bool flag1 = 1,flag2 = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != 1) flag1 = 0;
		if(a[i] >= 2) flag2 = 0;
	}
	if(flag1){
		cout << n / 2 << endl;
		return 0;
	}
	if(flag2){
		if(k == 1){
			int cnt = 0;
			for(int i = 1;i <= n;i++) cnt += a[i];
			cout << cnt << endl;
		}else if(k == 0){
			int cnt = 0;
			a[n + 1] = 2;
			for(int i = 1;i <= n;i++){
				if(a[i] == -1) continue;
				if(a[i] == 0) cnt++;
				else if(a[i] == a[i + 1]){
					cnt++;
					a[i + 1] = -1;
				}
			}
			cout << cnt << endl;
		}
		return 0;
	}
	int ind = 1;
	for(int i = 1;i <= n;i++){
		int sum = a[i];
		if(a[i] == k){
			q[ind].x = i,q[ind].y = i;
			ind++;
			continue;
		}
		for(int j = i + 1;j <= n;j++){
			sum = Xor(sum,a[j]);
			if(sum == k){
				q[ind].x = i,q[ind].y = j;
				ind++;
				break;
			}
		}
	}
	ind--;
	sort(q + 1,q + ind + 1,cmp);
	int ans = 1;
	int l = 1;
	for(int i = 2;i <= ind;i++){
		if(q[i].x > q[l].y){
			ans++;
			l = i;
		}
	}
	cout << ans << endl;
	return 0;
}

