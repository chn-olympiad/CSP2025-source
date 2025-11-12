#include <iostream>
#define mod 998244353
using namespace std;
int n,m,c[505],ans;
char s[505];
bool vis[505],f1,f2;
void dfs(int x,int cnt){
	if(x == n){
		ans = (ans+(bool)(n-cnt>=m))%mod;
		return;
	}
	for(int i = 0;i < n;i++){
		if(vis[i])
			continue;
		vis[i] = 1;
		dfs(x+1,cnt+(bool)(cnt>=c[i]||s[x]=='0'));
		vis[i] = 0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 0;i < n;i++){
		cin >> c[i];
		f2 |= !c[i];
	}
	for(int i = 0;s[i];i++)
		f1 |= (s[i]=='0');
	if(n > 10 && !f1 && !f2){
		ans = 1;
		while(n){
			ans = 1ll*ans*n%mod;
			n--;
		}
	}else{
		dfs(0,0);
	}
	cout << ans;
	return 0;
}
