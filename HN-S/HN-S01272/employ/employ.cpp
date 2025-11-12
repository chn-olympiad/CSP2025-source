#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000];
int vis[1000];
int pos[1000];
int n,k,cnt;
string s;
void dfs(int x){
	if(x==n+1){
		int yes=0,no=0;
		for(int i=1;i<=n;i++){
			if(no>=a[pos[i]])no++;
			else if(s[i]=='0')no++;
			else yes++;
		}
		if(yes>=k)cnt++;
		cnt%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			pos[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>k;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<cnt;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
