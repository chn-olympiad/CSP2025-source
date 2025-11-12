#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,s[(int)(5e3+114)];

int dfs(int now,int e,int last)
{
	int find=lower_bound(s+1,s+last,e-now)-s+1,cnt=0;
	if(find==last) return 0;
	printf("%d,%d ",find,last);
	if(now>e) return 1;
	for(int i=find;i>0;i--){
		cnt=(cnt+dfs(now+s[i],e,i))%998244353;
	}
	return cnt;
}

signed main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	s[0]=2e9;
	for(int now,i=1;i<=n;i++){
		now=s[i];
		ans+=dfs(now,now*2,i);
		printf("\n---\n%d\n",ans);
	}
	printf("%d",ans);
	return 0;
}


