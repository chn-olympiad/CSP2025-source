#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],cnt[2000005],sum[500005],id,ans=1;
struct node{
	int l,r;
}road[500005];
bool cmp(node x,node y){
	return x.r<y.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	memset(cnt,-1,sizeof cnt);
	cnt[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
		if(a[i]==k){
			road[++id].l=i;
			road[id].r=i;			
		}else if(cnt[sum[i]^k]>-1){
			road[++id].l=cnt[sum[i]^k]+1;
			road[id].r=i;
		}
		cnt[sum[i]]=i;
	}
	if(id==0){
		printf("0");
		return 0;
	}
	sort(road+1,road+1+id,cmp);
	int last=road[1].r;
	for(int i=2;i<=id;i++){
		if(road[i].l>last){
			ans++;
			last=road[i].r;
		}
	}
	printf("%lld",ans);
	return 0;
} 
