#include<bits/stdc++.h>
using namespace std;
#define lbt(i) (i&(-i))
#define ll long long
#define __int __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define psb push_back
#define lbd lower_bound
#define pbd upper_bound
#define endl '\n'

const int mx=20;
const ll mod=998244353;
int n,m,a[mx];
ll ans,f[1<<mx][mx];
string s;

int get(int x){
	int y=0;
	while(x){
		y+=(x&1);
		x>>=1;
	}
	return y;
}
int tp(int x){
	int y=0;
	while(x){
		y++;
		x>>=1;
	}
	return y;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(s=="\n") cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	f[0][0]=1;
	for(int i=1;i<(1<<n);i++){
		f[i][0]=1;
		for(int j=1;j<=n;j++){
			f[i][j]=f[i-lbt(i)][j];
			if(s[get(i)-1]=='1'&&get(i)-j<a[tp(lbt(i))]) (f[i][j]+=f[i-lbt(i)][j-1])%=mod;
		}
	}
	for(int i=m;i<=n;i++) (ans+=f[(1<<n)-1][i])%=mod;
	cout<<ans;
	return 0;
}
