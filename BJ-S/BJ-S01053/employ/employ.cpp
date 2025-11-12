#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=510;
int s[N],n,m,c[N];
const int mod=998244353;
string S;
long long ans;
bool vis[N];
int solve(){
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[s[i]]){
			cnt++;
		}
		else{
			if(S[i-1]-'0'){
				sum++;
			}
			else cnt++;
		}
	}
	return sum>=m;
}
void dfs(int cnt){
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			s[cnt]=i;
			dfs(cnt+1);
			vis[i]=0;
		}
	}
	if(cnt==n){
		ans+=solve();
	}
}
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
	bool flag=1;
	scanf("%d%d",&n,&m);
	cin>>S;
	for(int i=0;i<S.length();i++) if(s[i]!='1') flag=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(!flag){
		dfs(1);
	}
	else{
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
	}
	printf("%lld",ans);
}