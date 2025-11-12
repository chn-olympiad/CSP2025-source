#include<bits/stdc++.h>
using namespace std;
#define cfalse cin.tie(0)->sync_with_stdio(0)
#define endl "\n"
#define int long long
const int maxn = 2e5 + 5;
struct node{
	int a, b, c;
};
vector<node>mp;
int t, n;
bool cmp(node a, node b){
	return a.a > b.a;
}
void solve1(){
	sort(mp.begin(), mp.end(), cmp);
	int ans = 0;
	for(int i = 0; i < n / 2; i++){
		ans += mp[i].a;
	}
	cout << ans << endl;
}
struct nd{
	int a, id;
};
bool cmp1(nd n, nd m){
	return n.a > m.a;
}
int dp[maxn];
vector<nd>arr;
//对于两维，我们考虑第i个人是要选a还是选b，即要么a要么b，dp数组可以定义为前i个人，其中第i位选了a社团或b社团的最大值，考虑如何转移
//发现其实问题在于人数的限制，即有限个人数，要求贡献最大化，再定义一些数组以供转移？ 
//或者直接用一个dp数组进行转移，若不考虑空间
//则对于两个人的优化便可以转化成dp[i][j]表示第 
void solve2(){
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		arr.push_back({mp[i].a - mp[i].b, mp[i].b});
	}
	sort(arr.begin(), arr.end(), cmp1);
	for(int i = 0; i < arr.size() / 2; i++){
		if(arr[i].a < 0){
			ans += arr[i].a + arr[i].id;
		}else{
			ans += arr[i].id;
		} 
	}
	for(int i = arr.size() / 2; i < n; i++){
		ans += arr[i].id; 
	} 
	
	cout << ans << endl;
} 
int ansans = 0;
void dfs(int p, int a, int b, int c, int num){
	ansans = max(ansans, num);
	if(p == n){
		ansans = max(ansans, num);
		return;
	}
	if((a + 1) <= n / 2){
		dfs(p + 1, a + 1, b, c, num + mp[p].a);
	}
	if((b + 1) <= n / 2){
		dfs(p + 1, a, b + 1, c, num + mp[p].b);
	}
	if(c + 1 <= n / 2)dfs(p + 1, a, b, c + 1, num + mp[p].c);
}
void solve3(){
	ansans = 0;
	dfs(0, 0, 0, 0, 0);
	cout << ansans << endl;
}
//首先，先考虑前两项 
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cfalse;
	cin >> t;
	while(t--){
		cin >> n;
		mp.clear();
		node p;
		bool flag = 1, flag1 = 1;
		for(int i = 0; i < n; i++){
			cin >> p.a >> p.b >> p.c;
			if(p.c != 0)flag1 = 0;
			if(p.b != 0)flag = 0;
			mp.push_back(p);
		}
		if(flag && flag1){
			solve1();
//			continue;
		}else if(flag1){
			solve2();
//			continue;
		}else{
			solve3();
		}
		
	}
	return 0; 
}
//对于每个社团，其人数不能多于n / 2个人
//求最大贡献,考虑背包dp，但是貌似需要3维，记录有多少个人与多少个人分别参加了a与b社团 
