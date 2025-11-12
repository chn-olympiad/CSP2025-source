#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=200010;
int t,n;
int a[maxn],b[maxn],c[maxn];
int ans;
void dfs(int x,int cnt,int ct1,int ct2,int ct3){
	if(x==n+1){
		ans=max(ans,cnt);
		return;
	}
	if(ct1+1<=n/2)dfs(x+1,cnt+a[x],ct1+1,ct2,ct3);
	if(ct2+1<=n/2)dfs(x+1,cnt+b[x],ct1,ct2+1,ct3);
	if(ct3+1<=n/2)dfs(x+1,cnt+c[x],ct1,ct2,ct3+1);
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans=0;
		cin >> n;
		int cnt1=0,cnt2=0,cnt3=0,cnt=0;
		for(int i = 1;i <= n;i++) {
			cin >> a[i] >> b[i] >> c[i];
			cnt1+=a[i];
			cnt2+=b[i];
			cnt3+=c[i];
			cnt+=max(a[i],b[i]);
		}
		if(n>14&&cnt2==0&&cnt3==0){
			cout << cnt1 << endl;
			continue;
		}
		dfs(1,0,0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
