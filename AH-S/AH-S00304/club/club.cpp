#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[5];
long long a[100005][5],tmp,ans;
long long suf[100005];
void dfs(int now){
	if(now==n+1){
		ans=max(ans,tmp);
		return;
	}
	if(tmp+suf[now]<ans)return;
	for(int i=1;i<=3;i++){
		if(cnt[i]+1>(n>>1)){
			continue;
		}
		cnt[i]++;
		tmp+=a[now][i];
		dfs(now+1);
		cnt[i]--;
		tmp-=a[now][i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		memset(suf,0,sizeof suf);
		for(int i=n;i>=1;i--){
			long long mx=max(a[i][1],max(a[i][2],a[i][3]));
			suf[i]=suf[i+1]+mx;
		}
		tmp=ans=0;
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
