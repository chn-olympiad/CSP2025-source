#include<bits/stdc++.h>//35~50
using namespace std;
#define int long long
const int N=510;
const int mod=998244353;
int n,m,ans;
char s[N];
int c[N],xu[N];
bool vis[N];
bool chck(){
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			cnt++;
			continue;
		}
		if(cnt>=c[xu[i]]){
			cnt++;
			continue;
		}
		sum++;
	}
	if(sum<m) return 0;
	return 1;
}
void dfs(int x){
	if(x==n+1){
		if(chck()) ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			xu[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
			xu[x]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='1') cnt++;
	if(cnt==n){
		int sum=0;
		for(int i=n;i>=1;i--) ans=(ans*i)%mod;
		cout<<sum<<"\n";
		return 0;
	}else if(cnt<m){
		cout<<"0\n";
		return 0;
	}
	dfs(1);
	cout<<ans%mod<<"\n";
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

2204128
*/
/*
3 2
101
1 1 2
*/
/*
4 2
1001
1 1 2 3
*/
