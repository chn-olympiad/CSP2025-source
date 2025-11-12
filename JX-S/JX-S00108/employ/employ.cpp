#include <iostream>
#include <string>
using namespace std;
bool avi[501];
int c[501];
int n,m;
typedef unsigned long long ull;
ull divss = 998244353ll;
bool vis[501];
ull fact[501];
ull ans = 0;
void dfs(int i,int j,int k){// i:people count,j:leaving people,k:unpassed people
	if(i-k-j==m){
		//cout << ans << endl;
		ans = (ans+fact[n-i])%divss;
	}
	else {
		for(int z=1;z<=n;z++){
			if(!vis[z]){
				vis[z] = true;
				if(k>=c[z]) dfs(i+1,j+1,k);
				else dfs(i+1,j,k+1-avi[i]);
				vis[z] = false;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	cin >> n >> m;
	cin >> s;
	fact[0] = fact[1] = 1;
	for(int i=1;i<=500;i++) fact[i] = fact[i-1]*i%divss;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1')avi[i] = true;
		else avi[i] = false;
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	cout << fact[n];
	return 0;
}