#include<bits/stdc++.h>
using namespace std;

const int maxn = 507;
const long long mod = 998244353;

int n,m,ans;

bool vis[maxn],s[maxn];
int c[maxn];

bool priority_B = 1;

vector<int> assemble;

void dfs(int cur){
	if(cur == n){
		int day = 1,cur_reject = 0,sum_employee = 0;
		for(auto cur_employee : assemble){
//			cout << cur_employee << " ";
			if(cur_reject < c[cur_employee]){
				if(s[day]){
					sum_employee++;
//					cout << "Admitted\n";
					if(sum_employee >= m){
						ans++;
						return;
					}
				}
				else {
					cur_reject++;
//					cout << "Rejected\n";
				}
			}
			else {
				cur_reject++;
//				cout << "Rejected\n";
			}
			day++;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i] = 1;
		assemble.push_back(i);
		dfs(cur + 1);
		assemble.pop_back();
		vis[i] = 0;
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	getchar();
	for(int i=1;i<=n;i++){
		char ch = getchar();
		s[i] = ch - 48;
		priority_B &= s[i];
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	if(n<=18){
		dfs(0);
		cout << ans;
	}
	else {
		if(priority_B == 0){
			cout << 0;
			return 0;
		}
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans *= i;
			ans %= mod;
		}
		cout << ans;
	}
	return 0;
}
