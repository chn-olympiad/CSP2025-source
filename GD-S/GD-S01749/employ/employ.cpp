#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
const int my_MOD = 998244353;
typedef long long ll;
string s;
int c[N];
int n,m;
bool vis[N];
vector<int>v;
int ans = 0;
void dfs(int u){
	
	if(u == n + 1){
//		for(auto it:v){
//			cout << it << ' ';
//		}		
		//cout << "\n\n";
		int x = 0,res = 0;
		for(int i = 0;i < n;i++){
			int a = v[i],b = (s[i] - '0');
			//cout << x << ' ' << res << '\n';
			//cout << a << ' ' << c[a] << ' ' << b <<'\n';
			if(c[a] <= x){
				x++;
				continue;
			}
			if(b == 0){
				x++;
			}else{
				res++;
			}
		}
		
		if(res >= m){
			//cout << res << '\n';
			ans++;

			//cout << '\n';
			ans %= my_MOD; 
		}
		return;
	}
	
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		v.push_back(i);
		dfs(u + 1);
		v.pop_back();
		vis[i] = 0;
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	
	dfs(1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
