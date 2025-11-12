#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e3+5,M=998244353;
LL n,a[N],ans,sum[N];
LL dfs(LL cur,LL sum,LL maxn){
	if(cur==n){
		return sum>maxn*2;
	}
	LL ans=0;
	for(LL i=cur+1;i<=n;i++){
		ans+=dfs(i,sum+a[i],a[i]);
	}
	return ans%M;
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		LL a123=a[1]+a[2]+a[3];
		if(a123>max(a[1],max(a[2],a[3])))cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		LL cum=1;
		while(n>0){
			cum*=n;
			cum%=M;
			n--;
		}
		cout<<(cum/2)%M;
		return 0;
	}
	cout<<dfs(0,0,0);
	return 0;
}
