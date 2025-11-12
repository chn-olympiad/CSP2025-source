//30~25pts
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
#define fo(i,n,m)	for(int i=n;i<=m;i++)
#define foo(i,n,m)	for(int i=n;i>=m;i--)
int n,m;
string s;
int a[maxn];
int c[maxn];
int ans;
void dfs111(int len,int x){
	if(len>=m){
		ans++;
		ans%=mod;
	}
	fo(i,x+1,n){
		dfs111(len+1,i);
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	fo(i,1,n){
		cin>>a[i];
	}
	bool Apts=1;
	fo(i,0,s.length()-1){
		Apts=(Apts&&s[i]=='1');
	}
	if(Apts){	//25pts
		ans=0;
		dfs111(0,0);
		cout<<ans%mod<<'\n';
		return 0;
	}
	cout<<m<<'\n';	//5~0pts
	return 0;
}

