#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[5010];
long long ans;
bool flag=1;
const long long mod=998244353;

void dfs(int num,int ls,int maxn,int tot){
	if(num>3){
		if(tot>maxn*2)ans = (ans+1)%mod;
	}
	if(num==n+1)return;
	for(int i=ls+1;i<=n;i++)dfs(num+1,i,a[i],tot+a[i]);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)flag=0;
	}
	if(flag){
		for(int i=3;i<=n;i++){
			long long cnt=n,sum1=1,sum2=1;
			for(int j=1;j<=i;j++){
				sum1 = sum1*cnt%mod;
				sum2 = sum2*j%mod;
				cnt--;
			}
			ans+=sum1/sum2;
		}
		printf("%lld",ans);
		return 0;
	} //-------------------------------特判 
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}