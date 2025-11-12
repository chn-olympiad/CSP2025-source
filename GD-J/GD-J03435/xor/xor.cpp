#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,a[N],sum[N],tot;
struct node{
	int l,r;
}q[N];
map<int,int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
	mp[0]=0;
	for(int i=1;i<=n;i++){
		int tmp=sum[i]^k;
		if(mp.find(tmp)!=mp.end()){
			q[++tot].l=mp[tmp]+1;
			q[tot].r=i;
		}
		mp[sum[i]]=i;
	}
	int last=0,cnt=0;
	for(int i=1;i<=tot;i++){
		if(last<q[i].l ){
			cnt++;
			last=q[i].r;
		}
	}
	printf("%lld",cnt);
	return 0;
}

