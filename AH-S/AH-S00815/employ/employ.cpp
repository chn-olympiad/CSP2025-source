#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
long long c[505];
long long vis[505],f[505],ans;
const int mod=998244353;
bool check(string s1){
	memset(vis,0,sizeof(vis));
	long long cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){
			vis[i]=1;
			continue;
		}
		sum=0;
		for(int j=1;j<=i;j++)sum+=vis[j];
		if(sum>=c[s1[i-1]-'0'])vis[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])cnt++;
	}
	return cnt>=m;
}
void dfs(int id,string str){
	if(id==n+1){
		if(check(str))ans=(ans+1)%mod;
	}
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		string s1=str;
		f[i]=1;
		char c=i+'0';
		dfs(id+1,str+c);
		f[i]=0;
	}
}
bool check(){
	for(int i=0;i<n;i++){
		if(s[i]!='1')return 0;
	}
	return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,"");
	cout<<ans%mod;
	return 0;
}
