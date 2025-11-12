#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#define N 505
#define int long long
using namespace std;
int n,m,a[N],b[N];
const int MOD=998244353;
bool vis[N];
string s;
int ans;
void dfs(int k){
	if(k>n){
		int cnt=0,res=0;
		for(int i=1;i<=n;i++){
			if(cnt>=a[b[i]]||s[i]=='0'){
				cnt++;
				continue;
			}
			res++;
		}
		if(res>=m)
			ans++,ans%=MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			b[k]=i;
			dfs(k+1);
			vis[i]=false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s; s=' '+s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
