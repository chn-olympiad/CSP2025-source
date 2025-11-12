#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],a_max,mo=998244353,ans;
void dfs(int i,int j,int w,int v){
	for(int x=i+1;x<=j;x++){
		if(w-a[x]>v){
			ans++;
			dfs(x,j,w-a[x],v);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		for(int k=i-1;k>=2;k--){
			if(sum[k]>a[i]){
				ans++;
				for(int j=1;j<k-1;j++){
					if(sum[k]-sum[j]<=a[i]) break;
					ans++;
				}
				for(int j=2;j<=k;j++){
					if(sum[k]-a[j]<=a[i]) break;
					ans++;
					dfs(j,k,sum[k]-a[j],a[i]);
				}
			}
		}
		
	}
	cout<<ans%mo;
	return 0;
}