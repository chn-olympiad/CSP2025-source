#include<bits/stdc++.h>
#define int long long 
#define rep(i,a,b)	for(int i = (a);i<=(b);i++)
#define lep(i,a,b)	for(int i = (a);i>=(b);i--)
using namespace std;
const int N = 2e5+10;
const int M = 998244353;

int n,m,ans,a[N];
char ch[N];
int c[N];
bool vis[N];

inline void dfs(int x){
	if(x>n){
		int res = 0,cnt = 0;
		rep(i,1,n){
			if(cnt>=c[a[i]]){
				cnt++;
				continue;
			}
			if(ch[i] == '1')	res++;
			else{
				cnt++;
			}
		}
		if(res>=m)	ans++;
		ans%=M;
		return;
	}
	rep(i,1,n){
		if(!vis[i]){
			a[x] = i;
			vis[i] = 1;
			dfs(x+1);
			vis[i] = 0;
			a[x] = 0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cin>>n>>m;
	rep(i,1,n)	cin>>ch[i];
	rep(i,1,n)	cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
