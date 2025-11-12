#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long sum;
string sss;
int n,m,s1[506],c[506],a[505],vis[505],p[505],ss[505];
void dfs(int s,int k,int l){
	if(s>=m){
		sum=sum+p[n-k+1];
		sum%=mod;
		return;
	}
	if(s+ss[k]<m){
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(c[i]<=l||(s1[i]==0))dfs(s,k+1,l+1);
			else dfs(s+1,k+1,l);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>sss;
	p[0]=1;
	for(int i=1;i<=n;i++){
		p[i]=i*p[i-1]%mod;
	}
	for(int i=1;i<=n;i++){
		s1[i]=sss[i-1]-'0';
	}
	for(int i=n;i>=1;i--)ss[i]=ss[i+1]+s1[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	if(s1[1])dfs(1,1,0);
	else dfs(0,1,1);
	cout<<sum;
	return 0;
}

