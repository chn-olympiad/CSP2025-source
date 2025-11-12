#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,k,ans,vlim,pre[N],cnt[N*5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(cnt,-1,sizeof cnt);
	scanf("%d%d",&n,&k),cnt[0]=0;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		pre[i]=pre[i-1]^x;
		if(cnt[pre[i]^k]>=vlim) ans++,vlim=i;
		cnt[pre[i]]=i;
	}
	printf("%d",ans);
	return 0;
}
