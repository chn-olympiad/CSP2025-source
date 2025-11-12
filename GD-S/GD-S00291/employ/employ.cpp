#include<bits/stdc++.h>
#define N 505
using namespace std;
const int mod=998244353;
int n,m,a[N],t=0,a0,b[N],z[N],ans=0;
string s;
void dfs(int x){
	if(x>n){
		int o=0;
		for(int i=1;i<=n;i++){
			if(a[z[i]]<=o||s[i]=='0') o++;
		}
		if(n-o>=m) ans++; 
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			z[x]=i,b[i]=1;
			dfs(x+1);
			z[x]=0,b[i]=0;
		}
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s,s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i],t+=(s[i]-'0'),a0+=(a[i]==0);
	sort(a+1,a+n+1);
	if(m==1){
		if(t==0||a0==n) cout<<0;
	}else if(m==n){
		if(t!=n||a0>0) cout<<0;
		ans=1; 
		for(int i=n;i>=2;i--) ans=(ans*i)%mod;
		cout<<ans%mod;
	}else if(n<=10){
		dfs(1);
		cout<<ans;
	}
	return 0;
}
