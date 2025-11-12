#include<bits/stdc++.h>
#define rep(i,s1,s2,s3) for(i = s1;i <= s2;i += s3)
#define r(i,s1,s2,s3) for(i = s1;i >= s2;i -= s3)
#define ll long long
#define INF 0x7f7f7f7f
using namespace std;
const ll mod = 998244353;
int n,m,ans,sum[100010],c[100010];
bool v[100010];
string s;
int dfs(int x,int res){
	//if(sum[n] - sum[x - 1] + res < m) return 0;
	if(x > n) return res >= m;
	ll cnt = 0;
	for(int i = 1;i <= n;i++) if(!v[i]){
		v[i] = 1;
		cnt += dfs(x + 1,res + ((s[x] == '1') && (c[i] > (x - 1 - res))));
		v[i] = 0;
	}
	return cnt % mod;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    int i,j;
    if(n == m){
		cin>>s;
		s = '*' + s;
		rep(i,1,n,1) cin>>c[i];
		sort(c + 1,c + n + 1);
		rep(i,1,n,1) if(s[i] == '0'){
			cout<<0;
			return 0;
		}
		ans = 1;
		rep(i,1,n,1) ans = (ans * i) % mod;
		cout<<ans;
	}else if(m == 1){
		cin>>s;
		s = '*' + s;
		rep(i,1,n,1) cin>>c[i];
		sort(c + 1,c + n + 1);
		rep(i,1,n,1) if(s[i] == '1'){
			j = n;
			while(c[j - 1] > i) j--;
			break;
		}
		ans = 1;
		rep(i,1,n - 1,1) ans = (ans * i) % mod;
		cout<<ans * (n - j + 1);
	}else{
		cin>>s;
		s = '*' + s;
		rep(i,1,n,1) cin>>c[i];
		sort(c + 1,c + n + 1);
		int cnt = 0;
		rep(i,1,n,1) cnt += s[i] == '1';
		r(i,n,1,1) sum[i] = sum[i + 1] + (s[i] == '1');
		if(m > cnt) cout<<0;
		else cout<<dfs(1,0);
	}
    return 0;
}
