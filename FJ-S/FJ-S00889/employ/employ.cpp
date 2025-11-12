#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],ans,cnt,x,y;
string s;
bool fa,st[505];
void dfs(int sum,int cnt){
	if(sum+cnt>=n){
		if(sum>=m){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(st[i]==0){
			st[i]=1;
			if(a[i]&&b[i]>cnt-1-sum)dfs(sum+1,cnt);
			else dfs(sum,cnt+1);
			st[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		a[i+1]=s[i]-48;
		if(s[i]!=1)fa=1;
	}
	for(int i=1;i<=n;i++)cin>>b[i];
	if(fa==0){
		ans=1;
		for(int i=n;i>0;i--){
			ans*=i%998244353;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		cout<<0;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
