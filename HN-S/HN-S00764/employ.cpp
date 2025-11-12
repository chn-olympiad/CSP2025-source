#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N=998244353;
int const M=1e5+10;
int a[M],s[M],f[M],pt[M];
int n,m,ans;
void dfs(int x){
	if(x>n){
		int sum=0,num=0;
		for(int i=1;i<=n;i++){
			if(sum>=pt[s[i]]) return;
			if(a[i]==0) sum++;
			else num++;
		}
		if(num>=m) ans++;
		ans=ans%N;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		f[i]=1;
		s[x]=i;
		dfs(x+1);
		f[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++) cin>>pt[i];
	dfs(1);
	cout<<ans<<endl;
}
