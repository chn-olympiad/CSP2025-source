#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,mod=998244353;
int n,a[N],ans;
bool f1=1;
void dfs(int x,int sum,int cnt){
	if(x==n)return;
	if(sum>a[x]&&cnt>=2)ans++;
	dfs(x+1,sum,cnt),dfs(x+1,sum+a[x],cnt+1);
}
int pow_mod(int x,int k){
	if(k==1)return x;
	int f=pow_mod(x,k/2),g=f*f;
	if(k&1) return g*x;
	else return g;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],f1=f1&&(a[i]==1);
	sort(a,a+n);
	if(n<27) dfs(0,0,0);
	else if(f1) ans=(pow_mod(2,n)-n-n*(n-1)/2%mod-1+mod*n*n)%mod;
	cout<<ans;
	return 0;
}
