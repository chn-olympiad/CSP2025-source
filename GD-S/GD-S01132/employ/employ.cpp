#include<bits/stdc++.h>
using namespace std;
string s;
int a[510];
int b[510];
int c[510];
bool vis[510];
long long anss[510];
int cnt;
long long ans;
int n,m;
void dfs(int k){
	if(cnt+n-k+1<m){
		return;
	}
	if(k==n+1){
		if(cnt>=m){
			ans+=anss[k];
			ans%=998244353;
		}
		return;
	}
	int la=-1;
	for(int i=1;i<=n;i++){
		if(vis[i]||b[i]==la)continue;
		la=b[i];
		vis[i]=1;
		if(k-cnt>b[i]){
			c[b[i]]--;
			anss[k+1]=anss[k]*(c[b[i]]+1)%998244353;
			dfs(k+1);
			c[b[i]]++;
		}
		else if(a[k]==0){
			c[b[i]]--;
			anss[k+1]=anss[k]*(c[b[i]]+1)%998244353;
			dfs(k+1);
			c[b[i]]++;
		}
		else{
			cnt++;
			c[b[i]]--;
			anss[k+1]=anss[k]*(c[b[i]]+1)%998244353;
			dfs(k+1);
			cnt--;
			c[b[i]]++;
		}
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		a[i]=s[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		c[b[i]]++;
	}
	sort(b+1,b+1+n);
	anss[1]=1;
	dfs(1);
	cout<<ans;
	return 0;
}
