#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cnt=0;
ll a[1000001],dp[1000001],sum[1000001];
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
	for(int i=3;i<=n;i++){
		if(sum[i-1]>a[i]){
			int l=1,r=2;
			while(1){
				if(sum[r]-sum[l-1]>a[i]) cnt++;
				if(l==n-1 && r==n) break;
				r++;
				if(r>i-1){
					l++,r=l+1;
				}
			}
		}
	}
	printf("%d",cnt%998244353);



	return 0;
	fclose(stdin);
	fclose(stdout);
}

