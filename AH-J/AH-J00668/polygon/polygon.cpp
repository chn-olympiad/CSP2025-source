#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e4;
LL n,a[N],cnt;
bool vis[N],ok=1;
void dfs(LL cur,LL pre,LL sum,LL maxn){
	if(cur>n)	return;	
	for(LL i=pre+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(sum+a[i]>max(maxn,a[i])*2&&cur>=3)	cnt++;
			dfs(cur+1,i,sum+a[i],max(maxn,a[i]));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1)	ok=0;
	}
	if(ok){
		for(LL i=4;i<n;i++){
			LL x=i,sum=1;
			if(x>n/2)	x=n-i;
			for(LL j=n;j>=n-x+1;j--)	sum*=j;
			for(LL j=2;j<=x;j++)		sum/=j;
			cnt+=sum;
			cnt%=998244353;
		}
		if(n>=4)	cnt++;
	}
	
	else dfs(1,0,0,-1);
	//cout<<n<<endl;
	printf("%lld",cnt%998244353);
	return 0;
}
