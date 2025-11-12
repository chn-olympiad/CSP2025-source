#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
const int mod=998244353;
bool vis[100];
int a[100],n,m,c[100],s[100],ans;
string str;
bool check(){
	int cnt=0,tot=0;
	for(int i=1;i<=n;i++){
		int p=a[i];
		if(tot>=c[p]||str[i]=='0') tot++;
		else cnt++;
	}
	if(cnt>m) return true;
	else return false;
}
void dfs(int k){
	if(k>n){
		if(check()) ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			a[k]=i;
			dfs(k+1);
			vis[i]=false;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>str;
	for(int i=1;i<=str.length();i++) s[i]=str[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans%mod;
	return 0;
}
