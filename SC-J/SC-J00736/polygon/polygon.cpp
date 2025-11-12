#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn=5000+10;
int n,a[maxn],sum[maxn],ans;
void dfs(int pos,int len,int cnt,int xy){
	if(xy>sum[len]-sum[pos]) return;
	if(cnt>=2&&xy<=0&&pos==len) ans++;
	if(cnt>=len||pos>=len) return;
	dfs(pos+1,len,cnt+1,xy-a[pos+1]);
	dfs(pos+1,len,cnt,xy);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	if(n<=3){
		if(sum[n]>a[n]*2) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	for(int i=n;i>=3;i--) dfs(0,i-1,0,a[i]+1);
	cout<<ans<<endl;
	return 0;
}