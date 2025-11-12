#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],diff[5005];
long long ans;
int count(int x){
	int cnt=0;
	for(int i=n;i>=1;i--){
		if(a[i]<x){
			cnt+=i;
		}
	}
	for(int i=n-3;i>=1;i++){
		if(sum[i]<x){
			cnt+=i;
		}
	}
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=3;i--){
		if(sum[i-1]<=a[i]){
			continue;
		}
		else{
			diff[i]=sum[i-1]-a[i];
			ans=ans+1+count(diff[i]);
		}
	}
	cout<<ans;
	return 0;
}


