#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=500;
const int mod=998244353;
int n,m,c[N],s[N],ans;
char a[N];
bool flag[N];
void dfs(int d,vector<int> x){
	if (d==n){
		int sum=0;
		int fo=0;
		for (int i:x){
			if (fo>=i){
				fo++;
			}else{
				if (a[i]=='0') fo++;
				else sum++;
			}
		}
		if (sum>=m) ans=(ans+1)%mod;
	}
	for (int i=1;i<=n;i++){
		if (flag[i]){
			flag[i]=false;
			vector<int> ts=x;
			ts.push_back(c[i]);
			dfs(d+1,ts);
			flag[i]=true;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(flag,true,sizeof(flag));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>c[i];
	vector<int> ts;
	dfs(0,ts);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
