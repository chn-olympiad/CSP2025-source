#include <bits/stdc++.h>
using namespace std;
const int N=1010,mod=998244353;
int n,m;
string s;
int len;
int a[N],vis[N];
long long ans;
void dfs(int l,int num){
	if(l>len){
		if(num>=m) ans++,ans%=mod;	
		return ;
	}	
	for(int i=1;i<=n;i++){
		if(a[i]<=0||vis[i]==1) continue;
		vis[i]=1;
		if(s[l]=='0'){
			for(int j=1;j<=n;j++) a[j]--;
			dfs(l+1,num);
			for(int j=1;j<=n;j++) a[j]++;
		}
		else dfs(l+1,num+1);
		vis[i]=0;
	}
}
int main(){

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	len=s.size()-1;
	bool flag=1;
	for(int i=0;i<=len;i++){
		if(s[i]!='1'){
			flag=0;
			break;
		}
	}
	if(flag){
		ans=1;
		for(int i=1;i<=n;i++) ans*=i,ans%=mod;
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<ans;

	return 0;
}

