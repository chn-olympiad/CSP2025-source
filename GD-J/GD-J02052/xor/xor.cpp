#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5*1e5;
struct node{
	int l,r;
};
ll n,k,ar[N],sum[N],lst,ans,cnt;
node pre[N];
bool cmp(node x,node y){
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&ar[i]);
		sum[i]=sum[i-1]^ar[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				pre[++cnt].l=i;
				pre[cnt].r=j;
				break;
			}
		}
	}
	if(cnt==0||cnt==1){
		printf("%lld",cnt);
		return 0;
	}
	lst=pre[1].r;
	ans++;
	for(int i=2;i<=cnt;i++){
		if(pre[i].r<lst) lst=pre[i].r;
		if(pre[i].l>lst){
			ans++;
			lst=pre[i].r;
		}
	}
	printf("%lld",ans);
	
	
	return 0;
} 
