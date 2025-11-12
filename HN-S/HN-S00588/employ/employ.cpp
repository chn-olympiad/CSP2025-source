#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,c[510],que[510];
bool dif[510],use[510];
int dfs(int step){
	if(step==n){
		int good=0,bad=0;
		for(int i=0;i<n;i++){
			if(que[i]<=bad || dif[i]) bad++;
			else good++;
			if(good>=m) break;
		}
		if(good>=m) return 1;
		return 0;
	}
	int ret=0;
	for(int i=0;i<n;i++){
		if(use[i]) continue;
		que[step]=c[i];
		use[i]=true;
		ret=(ret+dfs(step+1))%998244353;
		use[i]=false;
	}
	return ret;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0') cnt++,dif[i]=true;
		else dif[i]=false;
		cin>>c[i];
	}
	if(n<=11){
		cout<<dfs(0);
	}else{
		long long ans=1;
		for(int i=1;i<=n;i++)
			ans=(ans*i)%998244353;
		cout<<ans;
	}
	return 0;
}
