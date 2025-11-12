#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
typedef long long ll;
ll t,n,b[3*N],a[N][5],cnt;
ll ans;
void dfs(ll k,ll s1,ll s2,ll s3,ll sum1,ll sum2,ll sum3) {
	if(k>n) {
		ans=max(ans,sum1+sum2+sum3);
		//cout<<s1<<" "<<s2<<" "<<s3<<" "<<ans<<endl;
		return ;
	}
		if(s1<n/2)dfs(k+1,s1+1,s2,s3,sum1+a[k][1],sum2,sum3);
		if(s2<n/2)dfs(k+1,s1,s2+1,s3,sum1,sum2+a[k][2],sum3);
		if(s3<n/2)dfs(k+1,s1,s2,s3+1,sum1,sum2,sum3+a[k][3]);
	

}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--) {
		ans=0;
		scanf("%lld",&n);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				scanf("%lld",&a[i][j]);
			}
			if(a[i][3]==0 && a[i][2]==0){
				cnt++;
				b[i]=a[i][1];
			}
		}
		if(cnt==n){
			sort(b+1,b+1+n);
			for(int i=n;i>=n/2;i--) ans+=b[i];
		}
		else{
			dfs(1,0,0,0,0,0,0);
		}
		printf("%lld\n",ans);

	}
	return 0;
}
