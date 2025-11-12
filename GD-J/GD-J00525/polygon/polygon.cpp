#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005];
//int x[5005],sum[5005],sum1[5005];
int n,ans=0;
void abc(int i,int h,int b){
	for(int j=i;j<=n;j++){
		if(b>=2){
			if(a[j]<h){
				ans++;
				ans%=998244353;
			}
			abc(j+1,h+a[j],b+1);
		}else{
			abc(j+1,h+a[j],b+1);
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
//		x[a[i]]++;
	}
	sort(a+1,a+n+1);
	abc(1,0,0);
//	for(int i=1;i<=5000;i++){
//		sum[i]=sum[i-1]+x[i];
//	}
//	for(int i=1;i<=n;i++){
//		sum1[i]=sum[i-1]+a[i];
//	}
//	int ans=0;
//	for(int i=3;i<=n;i++){
//		for(int j=1;j<=5000;j++){
//			
//		}
//	}
	cout << ans%998244353;
	return 0;
}
