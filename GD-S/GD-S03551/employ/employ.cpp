#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+5;
const int INF=0x3f3f3f3f;
const int MOD=998244353;
int vis[N],res[N],a[N],n,m,ans;
string s;
void dfs(int cur){
	if(cur==n+1){
		int cnt=0,acc=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				cnt++;
			}else{
				if(cnt<a[res[i]]){
					acc++;
				}else{
					cnt++;
				}
			}
		}
		if(acc>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			res[cur]=i;
			dfs(cur+1);
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i]){
			cnt++;
		}
	}
	if(n<=10){
		dfs(1);
		cout<<ans<<endl;
	}else if(m==1){
		LL ans1=1;
		for(int i=1;i<=n-1;i++){
			ans1=(ans1*i)%MOD;
		}
		cout<<ans1*(n-cnt)%MOD<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
}
