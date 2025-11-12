#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=(1LL<<60);
const int mod=998244353;
const int N=1e6+7;
bool use[N];
int c[N];
int n,m;

int fac[N],lim;
bool flag;

vector<int>num;
int dfs(int d,int o,int sum,int lv){
	if(d==n+1) return 1;
	if(o+sum>n-m) return 0;
	int res=0;
	if(flag){
		if(sum+lv==n-d+1) return fac[n-d+1];
		if(o+n-d+1-lv<=n-m) return fac[n-d+1];
	}
	if(use[d]==true){
		res=res+dfs(d+1,o+1,sum-1+c[o+1],lv)*sum%mod;
		for(auto i:num){
			if(i<=o) continue;
			if(c[i]==0) continue;
			c[i]--;
			res=res+dfs(d+1,o,sum,lv)*(c[i]+1)%mod;
			c[i]++;
		}
		res=res+dfs(d+1,o,sum,lv-1)*lv%mod;
	}else{
		res=res+dfs(d+1,o+1,sum-1+c[o+1],lv)*sum%mod;
		for(auto i:num){
			if(i<=o) continue;
			if(c[i]==0) continue;
			c[i]--;
			res=res+dfs(d+1,o+1,sum+c[o+1],lv)*(c[i]+1)%mod;
			c[i]++;
		}
		res=res+dfs(d+1,o+1,sum+c[o+1],lv-1)*lv%mod;
	}
	return res%mod;
}
string s;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
//	freopen("employ1.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;flag=true;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=n;i++) use[i]=(s[i-1]=='1'),flag=(flag&use[i]);
	int cntlv=0;
	for(int i=1,t;i<=n;i++){
		cin>>t;c[t]++;
		if(t>n-m) cntlv++;
	}
	lim=n-m;
	if(flag){
		int v=0;
		for(int i=0;i<=n-m;i++){
			if(v<i) cntlv=cntlv+c[i];
			else v=v+c[i],lim=i+1;
		}
	}
	for(int i=1;i<=lim;i++){
		if(c[i]!=0) num.push_back(i);
	}
	cout<<dfs(1,0,c[0],cntlv)<<"\n";
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
