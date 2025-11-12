#include<bits/stdc++.h>
using namespace std;
const int N=505;
typedef long long ll;
ll q,n,m,k;
ll c[N];
ll sum=0;
ll maxn;
ll now[N];
ll ans[N];
string s;

bool check(){
	ll num=n;
	memset(ans,0,sizeof(ans));

	for(int i=1;i<=n;i++){
		ans[now[i]]++;
		if(ans[now[i]]>=2) return false;
	
		if(c[now[i]]<=n-num) {
			num--;
			continue;
		}
		if(s[i-1]=='0') num--;
	}
	return num>=m;
}

void dfs(ll dep){
	if(dep==n+1){
		if(check()) {
			sum++;
			sum%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
			now[dep]=i;
			dfs(dep+1);
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	
	dfs(1);
	cout<<sum;
	return 0;
} 
//Ren5Jie4Di4Ling5%
/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

