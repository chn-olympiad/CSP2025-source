#include <bits/stdc++.h>
using namespace std;
string s;
int a[600];
int ans[600];
bool vis[600];
int n,m,count1;
void check(){
	int lose=0,cnt=0;
	for(int i=0;i<n;i++){
		if(lose<ans[i]&&s[i]=='1'){
			cnt++;
		}
		else lose++;
	}
	if(cnt>=m)count1++;
	count1=count1%998244353;
}
void dfs(int cnt){
	if(cnt==n){
		check();
		return ;
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			vis[i]=1;
			ans[cnt]=a[i];
			dfs(cnt+1);
			vis[i]=0;
		}
	}
}
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)cin>>a[i];
	dfs(0);
	cout<<count1;
	return 0;
}
/*
3 2
101
1 1 2
*/
