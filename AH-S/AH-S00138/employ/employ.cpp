#include <bits/stdc++.h>
using namespace std;
const long long MAXN=505,mod=998244353;
long long n,m,a[MAXN];
string s;
long long jc(long long x){
	long long sum=1;
	for(int i=1;i<=x;i++){
		sum=(sum*i)%mod;
	}
	return sum;
}
bool vis[MAXN];
int nx[MAXN];
long long sc;
bool ok(){
	int lq=0,xb=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'||xb>=a[nx[i]]){
			xb++;
		}
		else{
			lq++;
		}
	}
	return lq>=m;
}
void dfs(int t){
	if(t>n){
		sc+=ok();
		sc%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			nx[t]=i;
			vis[i]=1;
			dfs(t+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool ok=1;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'){
			ok=0;
		}
	}
	long long o=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			o++;
		}
	}
	if(n-o<m){
		cout<<0;
		return 0;
	}
	if(ok){
		cout<<((n-o)*jc(n-1))%mod;
	}
	else{
		dfs(1);
		cout<<sc;
	}
	return 0;
}
