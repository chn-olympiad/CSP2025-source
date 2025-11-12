#include<bits/stdc++.h>
using namespace std;
int a[100],vis[100];
int n,m;
int ans;
string s;
void dfs(int d,int cnt,int cnt2){
	if(d==n+1) {
		//cout<<cnt<<endl;
		if(cnt>=m) ans++,ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			vis[i]=1;
			if(s[d-1]=='1'&&cnt2<a[i]) dfs(d+1,cnt+1,cnt2);
			else {
				dfs(d+1,cnt,cnt2+1);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	
	cin>>s;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
