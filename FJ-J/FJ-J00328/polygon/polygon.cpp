#include<bits/stdc++.h>
using namespace std;
int a[5005],n,ans=0;
void dfs(int siz,int last,int now,int max,long long sum){
	if(now==siz){
		if(sum>a[max])ans++;
		ans%=998244353;
		return;
	}
	now++;
	for(int i=last+1;i<=max-(siz-now+1);i++){
		sum+=a[i];
		dfs(siz,i,now,max,sum);
		sum-=a[i];
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)for(int j=2;j+1<=i;j++)dfs(j,0,0,i,0);
	printf("%d\n",ans);
	return 0;
}