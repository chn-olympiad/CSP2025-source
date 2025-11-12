#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[510];
bool b[510];
long long ans;
long long f[505];
void dfs(int cnt,int num){
	if(num>=m){
		ans=(ans+max((int)f[n-num-cnt],1))%mod;
		return;
	}
	ans%=mod;
	if(cnt+num>=n) return;
	if(cnt>n-m) return;
	for(int j=1;j<=n;j++){
		if(b[j]) continue;
		b[j]=1;
		if(cnt<c[j]&&s[cnt+num]=='1') dfs(cnt,num+1);
		else dfs(cnt+1,num);
		b[j]=0;
	}
}
void dfs2(int k){
	if(k==n){
		ans++;
		ans%=mod;
	}
	for(int j=1;j<=n;j++){
		if(b[j]) continue;
		b[j]=1;
		if(k>=c[j]||s[k]=='0') dfs2(k+1);
		b[j]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	f[1]=1;
	for(int i=2;i<=n;i++) f[i]=(f[i-1]*i)%mod;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||c[i]==0){
				cout<<0;
				return 0;
			}
		}
		cout<<1;
		return 0;
	}
	if(m==1){
		dfs2(0);
		cout<<f[n]-ans;
		return 0;
	}
	//int jud=0;
//	while(jud<s.size()&&s[jud]=='1') jud++;
//	if(jud==s.size()){
//		int g=n;
//		for(int i=1;i<=n;i++)
//			if(c[i]=='0') g--;
//		cout<<f[g];
//		return 0;
//	}
	dfs(0,0);
	cout<<ans; 
	return 0;
} 
