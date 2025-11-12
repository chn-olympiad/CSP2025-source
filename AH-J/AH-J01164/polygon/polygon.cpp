#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],dp[5005];
long long he;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long mod=998244353;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int k=n;k>=3;k--){
		for(int h=k-1;h>=3;h--){
			for(int q=1;q<h;q++){
				if(a[h]+a[q]>=a[k]){
					int x=h-q-1;
					he=he+(1+x)*x/2;
					if(x==0&&a[h]+a[q]>a[k]){
						he++;
					}
					he%=mod;
				}
		    }
		}
	}
	cout<<he+1;
	return 0;
}
