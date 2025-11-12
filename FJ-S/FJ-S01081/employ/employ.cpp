#include<bits/stdc++.h>
using namespace std;
const int mod=998'244'353;
struct modint{
	int v;
	modint(int v=0):v(v){
	}
	modint operator+(const modint o)const{
		int t=v+o.v;
		if(t>=mod){
			t-=mod;
		}
		return t;
	} 
	modint operator-(const modint o)const{
		int t=v-o.v;
		if(t<0){
			t+=mod;
		}
		return t;
	} 
	modint operator*(const modint o)const{
		return 1ll*v*o.v%mod;
	} 
};
struct solution{
	int n,m;
	string s;
	vector<int> c;
	solution(int n,int m,string s,vector<int> c):n(n),m(m),s(s),c(c){
		flag.resize(n+2);
		p.resize(n+2);
	}
	vector<int> flag,p;
	bool check(){
		int cnt=0;
		int now=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'){
				if(c[p[i]]>cnt){
					now++;
				}
				else{
					cnt++;
				}
			}
			else{
				cnt++;
			}
		}
		return now>=m;
	}
	modint ans;
	void dfs(int i){
		if(i==n+1){
			if(check()){
				ans=ans+1;
//				for(int i=1;i<=n;i++){
//					cerr<<p[i]<<" ";
//				}
//				cerr<<endl;
			}
			return;
		}
		for(int j=1;j<=n;j++) if(!flag[j]){
			p[i]=j;
			flag[j]=1;
			dfs(i+1);
			flag[j]=0;
		}
	}
	int main(){
//		for(int i=1;i<=n;i++){
//			cin>>p[i];
//		}
//		cerr<<check()<<endl;
		ans=0;
		dfs(1);
		return ans.v;
	}
};
struct IO{
	int n,m;
	string s;
	vector<int> c;
	IO(){
		cin>>n>>m;
		cin>>s;
		c.resize(n+2);
		for(int i=1;i<=n;i++){
			cin>>c[i];
		} 
	}
	int ans;
	~IO(){
		cout<<ans<<"\n";
	}
};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	IO io;
	solution sol(io.n,io.m,io.s,io.c);
	io.ans=sol.main();
	return 0;
}
