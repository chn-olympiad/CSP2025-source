#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[5005];
void dfs(int id,int ch,long long maxn,long long mixn,string s){
	if(id>n)return ;
	if(ch>=3){
		if(mixn>maxn*2&&s[s.size()-1]=='b'){
			ans++;
			ans%=998244353;
		}
	}
	dfs(id+1,ch,maxn,mixn,s+"a");
	dfs(id+1,ch+1,max(maxn,a[id+1]),mixn+a[id+1],s+"b");
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0,0,"a");
	dfs(1,1,a[1],a[1],"b");
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
