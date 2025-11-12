#include<bits/stdc++.h>
using namespace std;
int sum[5010],a[5010],maxs[5010];
int n,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		maxs[i]=max(maxs[i-1],a[i]);
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			int maxn=-1;
			for(int k=i;k<=j;k++){
				maxn=max(maxn,a[k]);
			}
			if(sum[j]-sum[i-1]>maxn*2){
				ans=(ans+1)%998244353;
			}
		}
	}
	cout<<ans;
	return 0;
}
