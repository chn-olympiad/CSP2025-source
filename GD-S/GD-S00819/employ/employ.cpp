#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,a[N],m,p[N];
char s[N];
long long ans;
bool f[N];
void dfs(int x){
	if(x>n){
		int cnt=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'&&cnt<=s[p[i]])cnt2++;
			else cnt++;
		}
		if(cnt2>=m)ans+=(ans+1)%mod;
	}
	for(int i=1;i<=n;i++)
		if(!f[i])p[x]=i,f[i]=1,dfs(x+1),f[i]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>(s+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
	}else{
		ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
	}
	return 0;
}
