#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int a[510];
int st[510];
int sum[510];
int ans=0;
int n,m;
string str;
void dfs(int k,int s,int s2){
	if(k==n+1){
		if(s>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(st[i])continue;
		st[i]=1;
		if(k-1-sum[k-1]+s2<a[i]&&str[k-1]=='1')
			dfs(k+1,s+1,s2);
		else
			dfs(k+1,s,s2+1);
		st[i]=0;
	}
	return;
}
int jie(int x){
	int ans=1;
	for(int i=2;i<=x;i++){
		ans=ans*i%mod;
	}
	return ans%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	int len=str.size();
	bool f=1;
	for(int i=0;i<len;i++){
		if(str[i]!='1'){
			sum[i+1]=sum[i];
			f=0;
		}else{
			sum[i+1]=sum[i]+1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(sum[len-1]<m){
		cout<<0<<endl;
		return 0;
	}
	if(n<=18){
		dfs(1,0,0);
		cout<<ans<<endl;
		return 0;
	}
	
	if(f==1){
		if(len<m){
			cout<<0<<endl;
			return 0;
		}
		cout<<jie(n)<<endl;
	}
	return 0;
}
