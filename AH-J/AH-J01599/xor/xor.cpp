#include <bits/stdc++.h>
using namespace std;
int a[1010],s[1010],n,k;
struct node{
	int x,id,l;
}dp[1000010];
bool cmp(node x,node y){
	if(x.x!=y.x)return x.x<y.x;
	return x.id>y.id;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	int now=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				now++;
				dp[now*2].id=1;dp[now*2].x=i;dp[now*2].l=j-i+1;
				dp[now*2-1].id=0;dp[now*2-1].x=j;
			}
		}
	}
	sort(dp+1,dp+now*2+1,cmp);
	int ans=0,num=0,y=0;
	for(int i=1;i<=now*2;i++){
		if(dp[i].id==1&&dp[i].x>y){
			num++;
			y=dp[i].x+dp[i].l-1;
		}
		if(dp[i].id==1&&dp[i].x+dp[i].l-1<y){
			y=dp[i].x+dp[i].l-1;
		}
		ans=max(num,ans);
	}
	printf("%d\n",ans);
	return 0;
}
