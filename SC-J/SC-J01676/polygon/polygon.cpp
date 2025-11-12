#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,f[5005],flag[5005];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int step,int sum,int ma,int x){
	if(step>n){
		if(sum>ma*2){
			ans++;
			ans%=998244353;
		}
		return;
	}
	if(n-step+1>max(3-x,0))dfs(step+1,sum,ma,x);
	if(sum+f[step]>ma*2&&sum+f[step]>a[step]*2){
		if(x==0)dfs(step+1,sum+a[step],a[step],x+1);
		else dfs(step+1,sum+a[step],ma,x+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=n;i>=1;i--){
		f[i]=f[i+1]+a[i];
	}
	dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
}