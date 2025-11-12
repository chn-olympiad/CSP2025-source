#include<bits/stdc++.h>
using namespace std;
int a[10005],ss[10005];
int n,m;
int c[10005];
bool vis[10005];
string s;
int ans;
void dfs(int t){
	if(t>n){
		int sum=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				sum++;
			}
			else if(sum>=c[i]) sum++;
		}
		if(n-sum>=m) ans++;
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			vis[i]=1;
			c[t]=a[i];
			dfs(t+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
