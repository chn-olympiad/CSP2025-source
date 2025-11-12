#include<bits/stdc++.h>
#define for1(i,a,b) for(int i = (a);(i) <= (b);++(i))
#define for2(i,a,b) for(int i = (a);(i) >= (b);--(i))
#define pb push_back
#define pf push_front
using namespace std;
template<typename T> T cmax(T &x,T y){if(x < y) x = y;}
template<typename T> T cmin(T &x,T y){if(x > y) x = y;}
typedef long long LL;
#define int long long
typedef unsigned long long ULL;
const int N = 1e5 + 5;
const int M = 1e5 + 5;
const int mod = 998244353;
int n,m,ans;
LL qwq[N];
string str;
int c[505],h[505];
bool vis[505],flag;
void dfs(int x,int cnt){
    if(cnt+n-x+1<m) return ;
	if(cnt==m){
		ans=(ans+qwq[n-x+1])%mod;
		return ;
	}
	for1(i,1,n){
		if(!vis[i]){
            h[x]=i;
            vis[i]=1;
            if(str[x]=='1'&&x-1-cnt<c[i]) dfs(x+1,cnt+1);
            else dfs(x+1,cnt);
            vis[i]=0;
		}
	}
}
void solve(){
	qwq[0]=qwq[1]=1;
	for1(i,2,505) qwq[i]=i*qwq[i-1]%mod;
	cout<<qwq[101]<<"\n";
	cin>>n>>m>>str; str=" "+str;
	for1(i,1,n) cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return ;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
int testcase=1;
//cin>>testcase;
while(testcase--){
	solve();
}
    return 0;
}
