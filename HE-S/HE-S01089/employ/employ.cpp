#include<bits/stdc++.h>
using namespace std;
long long n,m,ans[1000],a[1003],h=0,vis[1003],f=0;
string s;
void dfs(int cnt){
	if(cnt==n+1){
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(sum-m>=0){
				break;
			}
			if(i-sum-1>n-m){
				break;
			}
			if(ans[i]<=i-sum-1){
				continue;
			}
			if(s[i-1]=='1'){
				sum++;
			}
		}
		if(sum>=m){
			h++;
			h%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			ans[cnt]=a[i];
			dfs(cnt+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	if(f==0){
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'&&i+1>=m){
				long long sum=1;
				for(int j=0;j<i+1;j++){
					sum*=n-j;
				}
				cout<<sum;
				return 0;
			}
		}
	}
	dfs(1);
	cout<<h%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
