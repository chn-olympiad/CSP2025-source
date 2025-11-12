#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
struct node{
	int a, b, c;
};
int t, n;
node a[N];
int f[210][210][210];
//第i个数，有j个人在1，k个人在2，l个人在3
//60pts
int ans;
void dfs(int num,int cnt1,int cnt2,int cnt3,int sum){
	if(num == n + 1){
		ans = max(ans, sum);
		return ;
	}
	if(cnt1 + 1 <= n / 2) dfs(num + 1, cnt1 + 1, cnt2, cnt3, sum + a[num].a);
	if(cnt2 + 1 <= n / 2) dfs(num + 1, cnt1, cnt2 + 1, cnt3, sum + a[num].b);
	if(cnt3 + 1 <= n / 2) dfs(num + 1, cnt1, cnt2, cnt3 + 1, sum + a[num].c);
}
bool cmp(node a, node b){
	return a.a > b.a;
}
void solve1(){
	ans = 0;
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1;i <= n / 2;i ++) ans += a[i].a;
	cout << ans << endl;
	return ;
}
void ff(){
	ans = 0;
	memset(f, -0x3f, sizeof f);
	f[0][0][0] = 0; 
	for(int i = 1;i <= n;i ++){
		for(int j = n / 2;j >= 0;j --){
			for(int k = n / 2;k >= 0;k --){
				int l = i - j - k;
				if(l > n / 2) continue;
				if(j != 0) f[j][k][l] = max(f[j][k][l], f[j - 1][k][l] + a[i].a);
				if(k != 0) f[j][k][l] = max(f[j][k][l], f[j][k - 1][l] + a[i].b);
				if(l != 0) f[j][k][l] = max(f[j][k][l], f[j][k][l - 1] + a[i].c);
			}
		}
	}
	for(int j = 0;j <= n / 2;j ++){
		for(int k = 0;k <= n / 2;k ++){
			int l = n - j - k;
			if(l > n / 2) continue;
			ans = max(ans, f[j][k][l]);
		}
	}
	cout << ans << endl;
	return ;
}
bool tmp2(node a, node b){
	return max(max(a.a, a.b), a.c) > max(max(b.a, b.b), b.c);
}
void solve2(){
	ans = 0;
	sort(a + 1, a + 1 + n, tmp2);
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for(int i = 1;i <= n;i ++){
		if(max(max(a[i].a, a[i].b), a[i].c) == a[i].a){
			if(cnt1 < n / 2){
				cnt1 ++, ans += a[i].a;
			}else{
				if(a[i].b > a[i].c && cnt2 < n / 2) cnt2 ++, ans += a[i].b;
				else cnt3 ++ , ans +=a[i].c;
			}
		}else if(max(max(a[i].a, a[i].b), a[i].c) == a[i].b){
			if(cnt2 < n / 2){
				cnt2 ++, ans += a[i].b;
			}else{
				if(a[i].a > a[i].c && cnt1 < n / 2) cnt1 ++, ans += a[i].a;
				else cnt3 ++ , ans +=a[i].c;
			}
		}else{
			if(cnt3 < n / 2){
				cnt3 ++, ans += a[i].c;
			}else{
				if(a[i].b > a[i].a && cnt2 < n / 2) cnt2 ++, ans += a[i].b;
				else cnt1 ++ , ans +=a[i].a;
			}
		}
	}
	cout << ans << endl;
	return ;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	bool f1 = 1, f2 = 1;
	while(t --){
		cin >> n;
		f1 = 1, f2 = 1;
		for(int i = 1;i <= n;i ++){
			scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
			if(a[i].c != 0) f2 = 0;
			if(a[i].b != 0) f1 = 0;
		}
		if(n <= 10){
			ans = 0;
			dfs(1, 0, 0, 0, 0);
			cout << ans << endl;
		}else if(n <= 200){
			ff();
		}
		else if(f1) solve1();//特殊性质A
		else solve2();
	}
	return 0;
}
