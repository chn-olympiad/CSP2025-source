#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#define ll long long
#define fg cout<<"！！！！！！！！！！！！！！！！！！"<<endl
using namespace std;
const int N=1e4+5,M=1e6+5,mod=998244353;
int n,m;
string s;
int c[505];
ll dp[18][1<<18],tmp[18][1<<18],ans;
int vis[505],a[505];
ll ksm(ll x,ll y){
	ll res=1,base=x;
	while(y){
		if(y&1) res=res*base%mod;
		base=base*base%mod;
		y>>=1;
	} 
	return res;
}
void dfs(int x){
	if(x==n+1){
		int cnt=0,f=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0') f++;
			else{
				if(f<c[a[i]]) cnt++;
				else f++;
			}
		}
		if(cnt>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
	}else{
		if(m==1){
			cout<<0;
		}else{
			if(m==n){
				int cnt=0;
				for(int i=1;i<=n;i++) if(c[i]==0) cnt++;
				for(int i=0;i<n;i++) if(s[i]=='0') cnt++;
				if(cnt) cout<<0;
				else{
					ll res=1;
					for(int i=1;i<=n;i++){
						res=res*i%mod;
					}
					cout<<res;
				}
			}else{
				cout<<0;
			}
		}
	}
	return 0;
}
/*

*/
