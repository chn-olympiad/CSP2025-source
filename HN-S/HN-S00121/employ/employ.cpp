#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
const int maxn=550;
int a[maxn];
bool flagA;
int cnt=0;
bool vis[maxn];
int ans[maxn];
int sum=0;
int p=0;
const int mod=998244353;
void dfs(int cur){
	if(cur>m){
		p++;
		for(int i=1;i<=m;i++){
			if(s[ans[i]]!='0'&&ans[i]>=sum)cnt++;
			else sum++;
		}
//		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&s[i]=='1'){
			vis[i]=1;
			ans[cur]=a[i];
			dfs(cur+1);
			vis[i]=0;
		}
	}
	return ; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s='#'+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')flagA=1;
	}
//	if(!flagA){
	dfs(1);
//	}
//	cout<<cnt%mod;
	cout<<p%mod;
	return 0;
} 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
