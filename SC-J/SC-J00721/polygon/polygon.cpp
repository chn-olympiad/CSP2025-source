#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005],f[5005],ans=0,n;
void dfs(int num,int sum,int mx){
	if(num<0||sum<0||mx<0)return;
	if(num>mx*2&&sum>=3){
		ans++;
		ans%=998244353;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			int mxn=max(mx,a[i]);
			cout<<num+a[i]<<" "<<sum+1<<" "<<mxn<<" "<<ans<<endl;
			dfs(num+a[i],sum+1,mxn);
			num-=a[i],sum--;
			f[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans-1;
	return 0;
}