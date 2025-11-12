#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[10005],w[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		w[i]=w[i-1]+a[i];
	}
	for(int l=1;l<=n-3;l++){
		for(int r=l+3;r<=n;r++){
			int qian=w[r]-w[l-1];
			if(qian>a[l]*2){
				int qqq=qian-(a[l]*2);
				int ans1=1;
				for(int k=r+1;k<=n;k++){
					if(a[r]-a[k]<qqq){
						ans1++;
					}
				}
				ans+=ans1;
			}
		}
	}
	cout<<ans%MOD;
	return 0;
}

