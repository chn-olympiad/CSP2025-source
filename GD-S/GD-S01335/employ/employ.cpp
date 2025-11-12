#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>


using namespace std;

long long vis[10005],a[10005],c[10005],ans=0;
long long n,m;string s;
long long mod=998244353;
void dfs(long long u){
	if(u>n){
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			if(cnt>=c[a[i]]){
				cnt++;continue;
			}
			if(s[i]=='0')cnt++,cnt%=mod;
		}
		if(n-cnt>=m){
			ans++;
		}
		return;
	}
	for(long long i=1;i<=n;i++){
		if(!vis[i]){
			a[u]=i;
			vis[i]=1;
			dfs(u+1);
			vis[i]=0;
		}
	}
}
	
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	
	cin>>s;
	s=" "+s;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}
	long long f=1;
	for(long long i=0;i<s.size();i++)if(s[i]=='0')f=0;
	if(f){
		long long ans=1;
		for(long long i=1;i<=n;i++)ans*=i,ans%=mod;
		cout<<ans<<endl;
	}
	
	return 0;
} 



