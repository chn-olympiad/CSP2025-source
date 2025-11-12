#include<bits/stdc++.h>
using namespace std;
const int N=510,M=998244353;
int ans=0,use[N],n,c[N],m;
string s;
void dfs(int now,int cnt){
	if(now>n&&cnt>=m)ans++;
	/*if(cnt==m){
		int sum=1;
		for(int i=1;i<=n-now;i++)sum=1ll*sum*i%M;
		ans=(ans%M+sum%M)%M;
	}*/
	for(int i=1;i<=n;i++){
		if(!use[i]){
			use[i]=1;
			if(s[now-1]=='1'&&c[i]>now-1-cnt)dfs(now+1,cnt+1);
			else dfs(now+1,cnt);
			use[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
}
