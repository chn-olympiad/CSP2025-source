#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[1005],f[1005],v[1005],p[1005],n,m,ans,jj=1;
void dfs(int d){
	if(d==n){
		int k=0;
		for(int i=0;i<n;i++)
			if(a[i]==0||k>=f[p[i]])k++;
		if(n-k>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!v[i])
			v[i]=1,p[d]=i,dfs(d+1),v[i]=0;
}
char c;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>c,a[i]=c-'0',jj&=a[i];
	if(jj==1){
		int num=1;
		for(int i=1;i<=n;i++)
			num=num*i%mod;
		cout<<num;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>f[i];
	dfs(0);
	cout<<ans;
}