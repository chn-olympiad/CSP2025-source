#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=501,MOD=998244353;
int n,m,p[N],c[N],ans=0;
string s;
bool used[N];
bool check(){
	int failed=0,cnt=0;
	for(int i=1;i<=n;++i){
		if(n-failed<m) return false;
		if(failed>=c[p[i]]||s[i]=='0'){
			++failed;
		}else{
			++cnt;
			if(cnt==m){
				return true;
			}
		}
	}
	return false;
} 
void dfs1(int u){
	if(u==n+1){
//		for(int i=1;i<=n;++i) cerr<<p[i]<<' ';
//		cerr<<'\n';
		if(check()){
			++ans;
			ans%=MOD;
		}
		return;
	}
	for(int i=1;i<=n;++i){
		if(!used[i]){
			p[u]=i;
			used[i]=1;
			dfs1(u+1);
			used[i]=0;
		}
	}
}
void Solve1(){
	dfs1(1);
	cout<<ans;
}
void Solve2(){
	ans=1;
	for(int i=2;i<=n;++i){
		ans=ans*i%MOD;
	}
	cout<<ans;
}
void Solve3(){
	
} 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>s;
	s=" "+s;
	bool special_A=1;
	for(int i=1;i<=s.size();++i){
		if(s[i]=='0'){
			special_A=0;
			break;
		} 
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	if(n<=18){
		Solve1();
		return 0;
	}else if(special_A){
		Solve2();
//		Solve3();
		return 0;
	}
	return 0;
}
