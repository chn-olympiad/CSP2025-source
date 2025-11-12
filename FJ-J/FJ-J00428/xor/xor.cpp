#include<bits/stdc++.h>
using namespace std;
int nr[1000005],n,k,cnt[3000005],s[1000005],a[1000005],f[1000005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k,memset(cnt,-1,sizeof(cnt));
	cnt[0]=0;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]^a[i],nr[i]=cnt[k^s[i]],cnt[s[i]]=i;
	for(int i=1;i<=n;i++) {
		if(nr[i]==-1)f[i]=f[i-1]; 
		else f[i]=max(f[i-1],f[nr[i]]+1);
	}
	cout<<f[n]<<endl;
	return 0;
}
