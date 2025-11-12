#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=600,p=998244353;
int n,m,c[N],fl[N],vis[N],a[N],ans,f[N][N];
string s;
bool che(){
	for(int i=1;i<=n;i++){
		if(s[i]=='0')return 0;
	}
	return 1; 
}
int sol(){
	int cnt=0,cnt1=0;
	for(int i=1;i<=n;i++){
		int t=a[i];
		if(cnt1<c[t]&&s[i]=='1'){
			cnt++;
		}else {
			cnt1++;
		}
		if(cnt>=m)break;
	}
	return cnt>=m;
}
void dfs(int len){
	if(len==n+1){
//		for(int i=1;i<=n;i++){
//			cout<<a[i]<<" ";
//		}
		if(sol()){
			ans++;
//			cout<<"aa";
		}
		
//		cout<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		a[len]=i;
		dfs(len+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	s='0'+s;
	fl[0]=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(che()){
		int cnt=0;
		for(int i=1;i<=n;i++){
			fl[i]=fl[i-1]*i;
			fl[i]%=p;
		}
		for(int i=1;i<=n;i++){
			if(c[i]!=0)cnt++;
		}
		
		for(int i=1;i<=n;i++){
			f[i][0]=f[i][1]=1;
			for(int j=1;j<=i;j++){
				if(j<c[i])
					f[i][j]=f[i-1][j]+f[i-1][j-1];
				else f[i][j]=f[i-1][j-1];
				f[i][j]%=p;
			}
		}
		int as=0;
//		if(cnt>=m){
//			cout<<fl[n];
//			return 0;
//		}
//		cout<<fl[cnt];
		for(int i=0;i<=n-m;i++){
			ans+=f[n][i];
		}
		cout<<ans<<'\n';
		return 0;
	}
	dfs(1);
//	a[1]=2,a[2]=1,a[3]=3;
//	cout<<sol();
	cout<<ans%p;
	return 0;
} 
