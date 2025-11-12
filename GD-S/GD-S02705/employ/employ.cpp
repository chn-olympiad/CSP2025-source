#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,m;
long long ans;
bool flag=1;
int s[505],c[505];
int a[505],vis[505];
void dfs(int num){
	if(num>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[a[i]]) cnt++;
			else if(s[i]==0) cnt++;
		}
		if(n-cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		a[num]=i;
		dfs(num+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char cao;
	for(int i=1;i<=n;i++){
		cin>>cao;
		s[i]=int(cao-'0');
		if(s[i]==0) flag=0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(flag==1){
		ans=1;
		for(int i=2;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans%mod;
		return 0;
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(m==1){
		long long k=1;
		int id;
		for(int i=2;i<n;i++) k=(k*i)%mod;
		for(int i=1;i<=n;i++){
			if(s[i]==1){
				id=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]>=id) ans=(ans+k)%mod;
		}
		cout<<ans%mod;
		return 0;
	}
	if(m==n){
		if(flag==0) cout<<0;
		return 0;
	}
	return 0;
}
