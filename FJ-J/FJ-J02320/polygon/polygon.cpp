#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans=0;
int n;
int a[5005];
void dfs(int m,int sum,int maxn,int p,bool b){
	if(sum>2*maxn && m>=3 && b==0){
		ans=(ans+1)%mod;
		b=1;
	}
	if(p>n) return;
	dfs(m+1,sum+a[p],max(maxn,a[p]),p+1,0);
	dfs(m,sum,maxn,p+1,b);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0,1,0);
	cout<<ans%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

