#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int a[505];
bool vis[505];
int b[505];
int cnt,x;
int ans=0;
void dfs(int x){
	if(x==n+1){
		cnt=0,x=n;
		for(int i=1;i<=n;i++){
			if(cnt>=a[b[i]] || s[i-1]=='0'){
				x--;
				cnt++;
			}
		}
		if(x>=m){
			//cout<<x<<" ";
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	cin>>n>>m;
	x=n;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(cnt>=a[i]){
			x--;
			cnt++;
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
