#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,mod=998244353;
int a[N],n,ans;
void dfs(int x,int ma,int sum,int p){
	if(x==n+1){
		if(sum>2*ma&&p>=3){
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(x+1,max(ma,a[x]),sum+a[x],p+1);
	dfs(x+1,ma,sum,p);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f){
		int r=1;
		for(int i=1;i<=n;i++){
			r*=2;
			r%=mod;
		}
		cout<<r-n-n*(n-1)/2-1;
	}else{
		dfs(1,0,0,0);
		cout<<ans;
	}
	
	return 0;
}
