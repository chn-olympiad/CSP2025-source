#include<bits/stdc++.h>
using namespace std;
int a[5010],n;
int dp[5010][5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	if(a[n]==1){
		cout<<((n-1)*(n-2))/2;
		
	}
//	for(int j=3;j<=n;j++){
//		for(int i=j;i<=n;i++){
//			int maxn=a[i];
//			
//		}
//	}
	return 0;
} 