#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353;
int n,m,ans;
string s;
int c[505];
int a[505],vis[505];
int add[105];
void dfs(int x){
	int p=0;
	for(int i=1;i<=x-1;i++){
		if(s[i-1]=='0')p++;
		else{
			if(c[a[i]]<=p)p++;
		}
	}
	if(x-1-p>=m){ans+=add[n-x+1],ans%=mod;return;}
	if(x>n)return;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	add[1]=add[0]=1;
	for(int i=2;i<=100;i++){
		add[i]=add[i-1]*i%mod;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans%mod<<endl;
	return 0;
}
