#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[10001];
long long n,m,ans;
bool book[10001];
string s;
void dfs(long long r,long long cnt,long long fall){
	if(cnt+r<m)return ;
	if(r==0){
//		cout<<cnt<<"x\n";
		if(cnt>=m)
			ans++,ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!book[i]){
//		cout<<r<<" "<<i<<" ";
			book[i]=1;
			if(a[i]<=fall)
				dfs(r-1,cnt,fall+1);
			else if(s[n-r]=='1')
				dfs(r-1,cnt+1,fall);
			else
				dfs(r-1,cnt,fall+1);
			book[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool flag=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0')flag=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)cnt++;
	} 
	if(n-cnt<m){
		printf("0");
		return 0;
	}
	if(flag){
		long long k=1;
		for(int i=2;i<=n;i++){
			k*=i%mod;
			k%=mod;
		}
		printf("%lld",k);
		return 0;
	}
	dfs(n,0,0);
	printf("%lld",ans);
	return 0;
} 
