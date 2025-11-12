//rp++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 1005;
bool pick[N];
char str[N];
int c[N];
ll n,m,ans;
void dfs(int idx,int gu){
	if(idx>n&&n-gu>=m){
		ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(pick[i]) continue;
		if(str[idx]=='0'||gu>=c[i]){
			pick[i]=true;
			dfs(idx+1,gu+1);
			pick[i]=false;
		} else {
			pick[i]=true;
			dfs(idx+1,gu);
			pick[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>str+1;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
