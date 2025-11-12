#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll n,m,s[510],c[510],a[510],vis[510],pd,pdpd,ans,cnt;
char ch;
void dfs(ll dep){
	if(dep==n+1){
		if(cnt>=m){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			continue;
		}else{
			vis[i]=1;
			bool pd=0;
			if(s[dep]==1){
				if(c[i]>(dep-cnt-1)){
					cnt++;
					pd=1;
				}
			}
			dfs(dep+1);
			vis[i]=0;
			if(pd==1){
				cnt--;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		s[i]=ch-'0';
		if(s[i]==0){
			pd=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			pdpd=1;
		}
	}
	if(m==n){
		if(pd==1||pdpd==1){
			cout<<"0";
			return 0;
		}else{
			ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=mod;
			}
			cout<<ans;
			return 0;
		}
	}
	if(pd==0&&pdpd==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n<=10){
		dfs(1);
	    cout<<ans%mod;
	    return 0;
	}
	cout<<"0";
	return 0;
} 


