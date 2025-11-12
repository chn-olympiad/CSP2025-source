//GZ-S00184 赫章新纪元学校 彭奥博
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,maxn=505;
int n,m;
string s;
int ans;
int p[maxn],sum[maxn],cnt,gv;
bool use[maxn];
void dfs(int dep){
	if(cnt>=m){
		int res=1;
		for(int i=2;i<=n-dep-1;i++)res=(res*i)%mod;
		ans=(ans+res)%mod;
		return;
	}
	if(dep==n){
		if(cnt>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=0;i<n;i++){
		if(!use[i]){
			use[i]=true;
			if(p[i]<=sum[i]+gv)gv++;
			else if(s[i]=='1')cnt++;
			dfs(dep+1);
			if(p[i]<=sum[i]+gv)gv--;
			else if(s[i]=='1')cnt--;
			use[i]=false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool flag=true;
	for(int i=0;i<n;i++)
		if(s[i]=='0'){
			flag=false;
			break;
		}
	if(m==n&&!flag)cout<<0;
	else if(flag){
		int res=1;
		for(int i=2;i<=n;i++)res=(res*i)%mod;
		cout<<res%mod;
	}else{
		sum[0]=(s[0]=='0');
		for(int i=1;i<n;i++)sum[i]=sum[i-1]+(s[i]=='0');
		for(int i=0;i<n;i++)cin>>p[i];
		dfs(0);
		cout<<ans%mod;
	}
	return 0;
} 
