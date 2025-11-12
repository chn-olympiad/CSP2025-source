#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[5010],s[5010];
int n;
int ans=0;
bool vis[5010];
vector<int> A;
void dfs(int j,int derta,int sum,int cnt,int last){
	if(cnt==j){
//		for(auto x:A){
//			cout<<x<<' ';
//		}
//		cout<<'\n'<<sum<<'\n';
		if(sum<=derta) ans=(ans+1)%mod;
		return;
	}
	for(int i=last;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
//			A.push_back(i);
			dfs(j,derta,sum+a[i],cnt+1,i);
//			A.pop_back();
			vis[i]=0;
		}
	}
}
int C(int n,int m){
	unsigned long long res=1;
	for(int i=n;i>=n-m+1;i--) res=res*i;
	for(int i=m;i>=1;i--) res/=i;
	return res%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i];
	sort(a+1,a+1+n);
	if(a[n]==1){
		ans=1;
		for(int i=3;i<n;i++){
			ans+=C(n,i);
			ans%=mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=3;i<=n;i++){//枚举最大 
		int num=a[i];
		int sum=s[i-1];
		if(sum<=num) continue;
		int derta=sum-num-1;
		int idx=upper_bound(a+1,a+1+i,derta)-a-1;//单个删可删到最远的下标 
//		cout<<idx<<'\n';
		if(idx==0){
			ans++;
			ans%=mod;
			continue;
		}
		ans+=idx+1;
		ans%=mod;
//		cout<<i<<'\n';
		for(int j=2;j<=idx;j++){//枚举删的个数 
			if(s[j]>derta) break;
			memset(vis,0,sizeof vis);
			dfs(j,derta,0,0,1);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
