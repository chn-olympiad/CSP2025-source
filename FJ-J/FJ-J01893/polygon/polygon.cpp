#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
int a[5010];
long long ans;
void dfs(int now,int d,int sum,int maxn){//now当前d深度sum和maxn最大值 
	maxn=max(maxn,a[now]);
	sum=sum+a[now];
	if(sum>2*maxn && d>=3){
		ans=(long long)(ans+1)%mod;
	}
//	printf("now:%d d:%d sum:%d maxn:%d ans:%d\n",now,d,sum,maxn,ans);
	for(int i=now+1;i<=(d>=2?n:(d>=1?(n-1):(n-2)));i++){
		dfs(i,d+1,sum,maxn);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		dfs(i,1,0,0);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
