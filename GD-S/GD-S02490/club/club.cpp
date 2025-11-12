#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][3],b[N],tp[N],cnt[3];
int solve(int x) {
	int cnt=0;
	for(int i=1; i<=n; i++) if(tp[i]==x) b[++cnt]=a[i][2]-a[i][1];
	sort(b+1,b+cnt+1);
	int ans=0;
	for(int i=1; i<=cnt-n/2; i++) ans+=b[i];
	return ans;
}
void work() {
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]) tp[i]=0,ans+=a[i][0];
		else if(a[i][1]>=a[i][0]&&a[i][1]>a[i][2]) tp[i]=1,ans+=a[i][1];
		else tp[i]=2,ans+=a[i][2];
	}
	for(int i=1; i<=n; i++) sort(a[i],a[i]+3);
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1; i<=n; i++) cnt[tp[i]]++;
	if(cnt[0]>n/2) cout<<ans-solve(0)<<"\n";
	else if(cnt[1]>n/2) cout<<ans-solve(1)<<"\n";
	else if(cnt[2]>n/2) cout<<ans-solve(2)<<"\n";
	else cout<<ans<<"\n";
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>T;
	while(T--) work();
	return 0;
}
