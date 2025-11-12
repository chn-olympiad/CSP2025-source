#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define endl '\n'

const int N = 1e5+5;
const int MOD = 10;

int n,a1,al2,a3;
int a[N][4];
int dp[N];
struct A{
	int j1,j2,j3;
}a2[N];

//dfs暴力解  n <= 10
int f[N],Realans;
void my_memset() {
	Realans = 0;
	for(int i=1; i <= n; i++) {
		a[i][1] = 0;a[i][2] = 0;a[i][3] = 0;
		a2[i].j1 = a2[i].j2 = a2[i].j3 = 0;
	}
	return;
}

void dfs(int k) {
	if(a1 > n/2 || al2 > n/2 || a3 > n/2) {
		return;
	}
	
	if(k > n) {
		int ans = 0;
		for(int i=1; i <= n; i++) {
			ans += f[i];
		}
		Realans = max(Realans,ans);
		return;
	}

	for(int i=1; i <= 3; i++) {
		f[k] = a[k][i];
		if(i == 1) a1 += 1;
		else if(i == 2) al2 += 1;
		else if(i == 3) a3 += 1;
		
		dfs(k+1);
		
		if(i == 1) a1 -= 1;
		else if(i == 2) al2 -= 1;
		else if(i == 3) a3 -= 1;
		f[k] = 0;
	}
	return;
}

//dp解 
bool cmp1(A x,A y) {
	return x.j1 > y.j1;
}
bool cmp2(A x,A y) {
	return x.j2 > y.j2;
}
bool cmp3(A x,A y) {
	return x.j3 > y.j3;
}

void iloveu() {
	sort(a2+1,a2+n+1,cmp1);
	for(int i=2; i <= n; i += 2) {
		dp[i] = dp[i-1] = max(max(a2[i-1].j1+a2[i].j2,a2[i-1].j1+a2[i].j3),max(max(a2[i-1].j2+a2[i].j1,a2[i-1].j2+a2[i].j3),max(a2[i-1].j3+a2[i].j1,a2[i-1].j3+a2[i].j2)));
	}
	int answer1 = dp[n];
	sort(a2+1,a2+n+1,cmp2);
	for(int i=2; i <= n; i += 2) {
		dp[i] = dp[i-1] = max(max(a2[i-1].j1+a2[i].j2,a2[i-1].j1+a2[i].j3),max(max(a2[i-1].j2+a2[i].j1,a2[i-1].j2+a2[i].j3),max(a2[i-1].j3+a2[i].j1,a2[i-1].j3+a2[i].j2)));
	}
	int answer2 = dp[n];
	sort(a2+1,a2+n+1,cmp3);
	for(int i=2; i <= n; i += 2) {
		dp[i] = dp[i-1] = max(max(a2[i-1].j1+a2[i].j2,a2[i-1].j1+a2[i].j3),max(max(a2[i-1].j2+a2[i].j1,a2[i-1].j2+a2[i].j3),max(a2[i-1].j3+a2[i].j1,a2[i-1].j3+a2[i].j2)));
	}
	int answer3 = dp[n];
	cout << max(answer1,max(answer2,answer3));
	return;
}

void solve() {
	my_memset();
	cin >> n;
	for(int i=1; i <= n; i++) {
		for(int j=1; j <= 3; j++) {
			cin >> a[i][j];
		}
		a2[i].j1 = a[i][1];
		a2[i].j2 = a[i][2];
		a2[i].j3 = a[i][3];
	}
	
	if(n <= 10) {
		dfs(1);
		cout << Realans << endl;
		return;
	} // 20分 
	else {
		iloveu();
		return;
	}
	return;
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
	cin >> T;
	
	while(T--) {
		solve();
	}
	
	return 0;
}	
