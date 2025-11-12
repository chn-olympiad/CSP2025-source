#include<bits/stdc++.h>
using namespace std;
int n,m,sum,flag;
string s;
int vis[110],c[510];
void dfs(int tot,int step){
	if(step>n&&tot>=m){
		sum++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int flag=0;
			if(s[step]=='1'&&c[i]>tot) flag=1;
			if(flag) tot++;
			vis[i]=1;
			dfs(tot,step+1);
			vis[i]=0;
			if(flag) tot--;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0') flag=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]=='0') flag=1;
	}
	if(n<=10){
		dfs(0,1);
		cout<<sum<<"\n";
	}
	if(n==m){
		if(flag==1) cout<<0<<"\n";
		else {
			long long ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=998244353;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
