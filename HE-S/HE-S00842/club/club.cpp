#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define ll long long
ll t, n, k, ans, maxn = 0, max1 = 0, max2 = 0, max3 = 0;

struct shiroko{
	ll one, two, three;
}a[M];

void dfs(ll n1, ll n2, ll n3, ll i){
	maxn = max(ans, maxn);
	if(i > n) return ;
	if(n1 != k && max1 != 0){
		ans += a[i].one;
		dfs(n1 + 1, n2, n3, i + 1);
		ans -= a[i].one;
	}
	if(n2 != k && max2 != 0){
		ans += a[i].two;
		dfs(n1, n2 + 1, n3, i + 1);
		ans -= a[i].two;
	}
	if(n3 != k && max3 != 0){
		ans += a[i].three;
		dfs(n1, n2, n3 + 1, i + 1);
		ans -= a[i].three;
	}
}

bool cmp1(shiroko a, shiroko b){
	return a.one > b.one;
}

bool cmp2(shiroko a, shiroko b){
	return a.two > b.two;
}

bool cmp3(shiroko a, shiroko b){
	return a.three > b.three;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		k = n / 2;
		for(int i = 1;i <= n;i++){
			cin >> a[i].one >> a[i].two >> a[i].three;
			max1 = max(max1, a[i].one);
			max2 = max(max2, a[i].two);
			max3 = max(max3, a[i].three);
		}
		if(max1 == 0 && max2 == 0){
			sort(a + 1, a + n + 1, cmp3);
			for(int i = 1;i <= k;i++) maxn += a[i].three;
			cout << maxn << endl;
			continue;
		} else if(max1 == 0 && max3 == 0){
			sort(a + 1, a + n + 1, cmp2);
			for(int i = 1;i <= k;i++) maxn += a[i].two;
			cout << maxn << endl;
			continue;
		} else if(max2 == 0 && max3 == 0){
			sort(a + 1, a + n + 1, cmp1);
			for(int i = 1;i <= k;i++) maxn += a[i].one;
			cout << maxn << endl;
			continue;
		}
		dfs(0, 0, 0, 1);
		cout << maxn << endl;
		ans = 0, maxn = 0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
