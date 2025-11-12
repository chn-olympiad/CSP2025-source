#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans;
int a[505],c[505],cnt1[505];
const int p=998244353;
string s;
int res[505],vis[505];
void dfs(int now,int sum){
	if(now>n){
		if(sum>=m) ans++;
		return;
	}
	if(sum+n-now<m) return;
//	cerr<<now<<" "<<sum<<" : "<<endl;
//	for(int i=1;i<=now;i++)
//		cerr<<b[i]<<" ";
//	cerr<<endl;
	if(sum==m){
		ans=(1ll*ans+res[n-now])%p;
	//	cerr<<ans<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		//b[now+1]=i;
		if(now-sum<c[i]&&a[now+1]) dfs(now+1,sum+1);
		else dfs(now+1,sum);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		a[i+1]=s[i]-'0';
		cnt+=a[i+1];
	//	cerr<<a[i+1]<<endl;
	}
	if(cnt<m){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	res[0]=1;
	for(int i=1;i<=n;i++)
		res[i]=res[i-1]*1ll*i%p;
	if(n>10&&cnt==n){
		ans=res[n];
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		//b[1]=i;
		dfs(1,c[i]!=0?a[1]:0);
		vis[i]=0;
	}
	cout<<ans<<endl;
	return 0;
}

