#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fre(X) freopen(X".in","r",stdin),freopen(X".out","w",stdout)
#define Xueli return
#define Chang 0
using namespace std;
namespace did{
	int n,m;
	string s;
	int c[505]; 
	const int mod=998244353;
	int jc(int n){
		if(n==1)return 1;
		return (jc(n-1)*n)%mod;
	}int ans=0;
	int p[505];
	bool v[505];
	int check(){
		int fail=0;
		int y=0;
		for(int i=1;i<=n;i++){
			if(fail>=c[p[i]]){
				fail++;
				continue;
			}
			if(s[i]=='0'){
				fail++;
				continue;
			}
			y++;
		}
		return y;
	}
	void dfs(int u=1){
		if(u>n){
			if(check()>=m)ans++;
			return;
		}
		for(int i=1;i<=n;i++){
			if(v[i]==1)continue;
			p[u]=i;
			v[i]=1;
			dfs(u+1);
			v[i]=0;
		}
	}
	void init(){

	}
	void lusolve(){
		cin>>n>>m>>s;
		s=' '+s;
		for(int i=1;i<=n;i++)cin>>c[i];
		if(m==n){
			int p=1;
			for(int i=1;i<=n;i++){
				if(c[i]==0||s[i]=='0')p=0;
			}
			if(p)cout<<jc(n);
			else cout<<0;
		}else {
			dfs();
			cout<<ans;
		}
	}
}
signed main(){
	IOS();
	fre("employ");
	int Q=1;
//	cin>>Q;
	did::init();
	while(Q--)did::lusolve();
//while(1);
	Xueli Chang;
}
//s MB
//s MB
/*
羊了个羊出题人吗? 
*/
