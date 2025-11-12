#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5,mod=998244353;
long long n,m,sum,ans=1,a[maxn];
bool b[maxn];
string s;
void dfs(long long x,long long cnt,long long z){
	if(x==n){
		if(cnt>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i])continue;
		b[i]=true;
		if(a[i]<=z||s[x]=='0')dfs(x+1,cnt,z+1);
		else dfs(x+1,cnt+1,z);
		b[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++)sum+=s[i]-'0';
	for(int i=1;i<=n;i++)cin>>a[i];
	if(sum==s.size()){
		memset(a,0,sizeof(a));
		memset(b,true,sizeof(b));
		for(int i=n,j=1;j<=m;i--,j++)a[j]=i;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m&&a[i]!=1;j++)
				if(b[j]&&a[i]%j==0)b[j]=false,a[i]/=j;
		for(int i=1;i<=m;i++)ans=(ans*a[i])%mod;
		cout<<ans<<'\n';
	}else{
		ans=0;
		dfs(0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
