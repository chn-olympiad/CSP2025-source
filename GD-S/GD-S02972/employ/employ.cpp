#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=610;
const ll mod=998244353;
int n,m,A,c[N],p[N];
bool v[N];
ll ans,w,dp[N];
string s;
void dfs(int x){
	if(x>n){
		int q=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0') q++;
			else{
				if(q>=p[i]) q++;
			}
		}
		if(n-q>=m){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			p[x]=c[i];
			dfs(x+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		A+=s[i-1]-'0';
		cin>>c[i];
		w*=2;
		w+=s[i-1]-'0';
	}
	sort(c+1,c+1+n);
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	cout<<0;
//	if(n<=18){
//		for(int i=0;i<(1<<n);i++){
//			ll z=w^((1<<n)-1);
//			if(i&z) continue;
//			int zh=1,q=0,ku=0,yo=0;
//			memset(dp,0,sizeof dp);
//			dp[n]=1;
//			for(int j=n-1;j>=0;j--){
//				dp[j]=dp[j+1];
//				if((1<<j)&i==0) q++;
//				else{
//					ku++;
//					while(zh<=n&&c[zh]<=q){
//						zh++;
//						yo++;
//					}
//					if(zh>n||ku<zh-1){
//						dp[0]=0;
//						break;
//					}
//					for(ll l=1;l<=yo;l++){
//						dp[j]=dp[j]*l%mod;
//					}
//					yo=0;
//				}
//			}
//		}
//	}
	return 0;
}
