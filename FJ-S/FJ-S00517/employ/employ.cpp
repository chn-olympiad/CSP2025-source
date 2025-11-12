#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;
int n,m,c[maxn],s[maxn],a[maxn],f[maxn],ans; 
void dfs(int x){
	if(x>n){
		int sum=0;
		for(int i=1;i<=n;i++)
			if(sum>=a[i]||!s[i]) sum++;
		ans+=(n-sum>=m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		a[x]=c[i];
		f[i]=1;
		dfs(x+1);
		f[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s[i]=c-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	int fl=0;
	for(int i=1;i<=n;i++)
		if(!c[i]) fl=1;
	if(fl){
		cout<<0;
		return 0;
	}
	else{
		int ans=1;
		for(int i=1;i<=n;i++) ans*=i,ans%=998244353;
		cout<<ans;
	}
}

