#include<bits/stdc++.h>

using namespace std;

const long long N=5e2+5;

long long n,m,a[N];
string s;

long long ans=0;
bool v[N];

void dfs(long long ip,long long c,long long sum){
	v[ip]=1;
	if(sum>=m){
//		cout<<ip;
		ans++;
		ans%=998244353;
//		return;
	}
	if(sum==n) return;
	for(long long i=1;i<=n;i++){
		if(v[i]) continue;
		if(c>=a[i]) continue;
		if(s[ip]=='1') dfs(i,c,sum+1);
		else dfs(i,c+1,sum);
	}
	v[ip]=0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) dfs(i,0,0);
	cout<<ans;
	return 0;
}
