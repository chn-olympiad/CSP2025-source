#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,k,a[N],sum[N],l[N],maxx;
map<int,int>mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==1)sum[i]=a[i];
		else sum[i]=a[i]^sum[i-1];
	}
	mp[0]=500005;
	for(int i=1;i<=n;i++){
		int id=sum[i]^k;
		l[i]=max(l[i],l[i-1]);
		if(mp[id]){
		l[i]=max(l[mp[id]]+1,l[i]);
		if(l[i]>l[mp[id]])
		mp[sum[i]]=i;
		}
		else mp[sum[i]]=i;
	}
	printf("%lld",l[n]);
	return 0;
}
