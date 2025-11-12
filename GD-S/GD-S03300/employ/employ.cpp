#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<long long, long long>
#define db double;
#define endl "\n"

const int MXN = 500,MOD = 998244353;
int n, m, cnt0, cnt1, nos;
string s;
int c[MXN],bin[MXN];
vector<pii> slins;
vector<int> lens;

int A(int a,int b){
	int res = 1;
	if(b < a)swap(a,b);
	for(int i = b-a+1; i <= b; i++){
		res = res*i%MOD;
	}
	return res;
}

int dfs(int p){
	if(p == 0){
		int res = 1;
		int tmp = 0;
		for(int i = nos-1; i >= 1; i--){
			res = res*A(bin[i]-tmp,lens[i])%MOD;
			tmp += lens[i];
		}
		res = res*A(n-tmp,n-tmp)%MOD;
		return res;
	}
	int res = 0;
	for(int i = 0; i < nos; i++){
		if(lens[i] > 0){
			lens[i]--;
			res = (res+dfs(p-1))%MOD;
			lens[i]++;
		}
	}
	return res;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	
	int l = 0;
	for(int r = 1; r <= n; r++){
		if(s[r] == 0 && l != 0){
			if(l != 0){
				slins.push_back({l,r-1});
				l = 0;
			}
			cnt0++;
		}
		else if(s[r] == 1){
			if(s[r-1] == 0)l = r;
			cnt1++;
		}
	}
	nos = slins.size();
	
	for(int i = 1; i <= n; i++){
		bin[c[i]]++;
	}
	for(int i = n-1; i >= 0; i--){
		bin[i] += bin[i+1];
	}
	
	for(pii i: slins){
		lens.push_back(i.second-i.first+1);
	}
	
	cout << dfs(n - m - cnt0);
	
	return 0;
}

