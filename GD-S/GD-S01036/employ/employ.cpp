#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500,mod=998244353,inf=0x3f3f3f3f3f3f;
int n,m,sum[N],c[N],cnt[N],maxx=-inf,k=0,ans=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=0;i<n;i++)
		sum[i+1]=sum[i]+(s[i]=='0');
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		cnt[c[i]]++;
		maxx=max(maxx,c[i]);
	}
	for(int i=maxx;i>=0;i--)
		cnt[i]+=cnt[i+1];
	for(int i=n;i>n-m;i--) sum[i]=0;
	sort(sum+1,sum+1+n);
	for(int i=n;i>=1;i--){
		ans*=(cnt[sum[i]]-k);
		ans%=mod;
		k++;
	}
	printf("%lld",ans);
    return 0;
}

