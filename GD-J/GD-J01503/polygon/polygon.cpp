#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],cnt[N],b[N],ans,f=1;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i],b[i]=i,f*=i;
	for(int i=1;i<=f;i++){
        int maxn=max(a[b[1]],a[b[2]]),sum=a[b[1]]+a[b[2]];
        for(int i=3;i<=n;i++){
            maxn=max(maxn,a[b[i]]),sum+=a[b[i]];
            if(sum>maxn*2){
            	cnt[i]++;
			}
        }
        next_permutation(b+1,b+n+1);
	}
	for(int i=1;i<=n;i++){
        for(int j=2;j<=i;j++) cnt[i]/=j;
        ans+=cnt[i];
	}
	cout << ans;
	return 0;
}

