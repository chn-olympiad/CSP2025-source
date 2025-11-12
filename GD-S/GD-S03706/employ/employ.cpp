#include<bits/stdc++.h>
using namespace std;
int in(){
	int ans=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) ans=ans*10+c-'0';
	return ans*f;
}
const int mod=998244353;
int n,m;
string s;
int c[510];
int ans;
int b[510];
int fac[510];
void dfs(int p,int cq,int cnt){
	if(cnt>=m){
		ans=(ans+fac[n-p+1])%mod;
		return;
	}
	if(p>n){
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			if(cq<c[i]){
				if(s[p-1]=='0') dfs(p+1,cq+1,cnt);
				else dfs(p+1,cq,cnt+1);
			}
			else dfs(p+1,cq+1,cnt);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in();m=in();
	int fl=1;
	fac[0]=1;
	cin>>s;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=n;i++){
		c[i]=in();
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
