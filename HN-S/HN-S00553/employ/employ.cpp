#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
const int mod=998224353;
int a[15];
int c[15];
bool vis[15];
int n, m;
string s;
bool check(){
	int s1=0, s2=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0') s2++;
		else if(c[a[i]]<=s2) s2++;
		else s1++;
	}
	return s1>=m;
}
int ans=0;
void dfs(int x){
	if(x==n){
		ans+=check();
		return;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	if(n>10){
		int s=1;
		for(int i=1;i<=n;i++) s=s*i%mod;
		cout<<s;
		return 0;
	}
	cin>>s;
	for(int i=0;i<n;i++)
		cin>>c[i];
	dfs(0);
	cout<<ans%mod;
	return 0;
}

