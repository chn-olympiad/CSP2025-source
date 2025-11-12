#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL mid = 998244353;
LL n,m,a[510],b[510],ans;
string s;
bool vis[510];
void dfs(LL now){
	if(now==n+1){
		LL nx=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||nx>=a[b[i]]){
				nx++;
			}else{
				cnt++;
			}
		}
		if(cnt>=m) ans++;
		if(ans>=mid) ans%=mid;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		b[now]=i;
		dfs(now+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=32){
		dfs(1);
		cout<<ans%mid;
	}else{
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			if(ans>=mid) ans%=mid;
		}
		cout<<ans%mid;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
