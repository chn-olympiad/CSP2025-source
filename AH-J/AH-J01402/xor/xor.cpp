#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],c[500005],cnt[2000005],ans,t=-1;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    memset(cnt,-1,sizeof(cnt));
    cnt[0]=0;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=c[i-1]^a[i];
		cnt[c[i]]=i;
		if((cnt[c[i]^k]!=-1&&cnt[c[i]^k]>t&&cnt[c[i]^k]!=i)||a[i]==k){
			ans++;
			t=i;
		}
	}
	cout<<ans;
    return 0;
}
