#include<bits/stdc++.h>
using namespace std;

const int N=507; 
int mod=998244353,ans,a[N],b[N],qz[N],n,m;
string s;
bool v[N];

bool check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(i-qz[i]<b[i])sum++;
	} 
	if(sum>=m)return 1;
	return 0;
} 
void dfs(int u){
	ans%=mod;
	if(u==n+1){
		if(check()){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		b[u]=a[i];
		dfs(u+1);
		v[i]=0;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int len=s.length();
	for(int i=1;i<=len;i++){
		qz[i]=qz[i-1]+s[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans%mod;
	return 0;
}
