#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans=0,dp[500010],lst=0,maxn=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int res=0,sum=0;
		for(int h=i;h>=lst+1;h--){
			if(h==i) res=a[h];
			else res=a[h] xor res;
			if(res==k) {
				sum++;
				break;
			}
		}
		if(res==k){
			dp[i]=dp[lst]+sum;
			maxn=max(dp[i],maxn);
			lst=i;
		} 
	}
	cout<<maxn;
	return 0;
}
