#include<iostream>
using namespace std;
#define ll long long
const ll mod=998244353;
int n;
int a[5005];
ll s[5005],ans;
void dfs(int k,ll sum,int mx,int cnt){
	if(k>n) return;
	if(sum+s[n]-s[k-1]<mx*2) return;
	if((sum+a[k])>max(mx,a[k])*2&&cnt+1>=3)
		ans=(ans+1)%mod;
	dfs(k+1,sum+a[k],max(mx,a[k]),cnt+1);
	dfs(k+1,sum,mx,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i];
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
