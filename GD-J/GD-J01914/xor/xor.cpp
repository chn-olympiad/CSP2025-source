#include<bits/stdc++.h>
#define ll long long 
#define LOCAL 0
#define ONLINE 1
using namespace std;
const int N=3e6+44;
ll n,k,a[N],b[N],ans,cnt[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	#if LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	#if ONLINE
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	#endif
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)b[i]=b[i-1]^a[i];
	memset(cnt,-1,sizeof cnt);
	cnt[0]=0;
	for(int i=1;i<=n;i++)cnt[b[i]]=max(max(cnt[b[i]],cnt[b[i-1]]),cnt[k^b[i]]+1),ans=max(cnt[b[i]],ans);
	cout<<ans;
	return 0;
} 
