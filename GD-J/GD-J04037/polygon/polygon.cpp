#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
const int f=998244353;
int n;
int a[maxn];
int mx[maxn]; 
long long q[maxn];
long long ans=0;
long long dp[maxn][maxn];
long long l[maxn][maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
		mx[i]=a[i]*2;
	}
	for(int i=3;i<=n;i++){
		if(q[i]>mx[i])ans=(ans+f+1)%f;
	}
	for(int i=4;i<=n;i++){ 
		for(int j=1;j<=i-3;j++){
			if(q[i]-q[j]>mx[i]){
				ans=(ans+f+1)%f;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

