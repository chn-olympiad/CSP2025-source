#include<bits/stdc++.h>
using namespace std;
int n,a[5500],b[510000],c[510],f[5500],mod=998244353,sum,maxx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx+=a[i];
	}
	sort(a+1,a+1+n);
	if(a[n]==1){
		f[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=i;j>=1;j--){
				f[j]=(f[j]+f[j-1])%mod; 
			}
		}
		for(int i=3;i<=n;i++){
			sum=(sum+f[i])%mod;
		}
		cout<<sum;
	}
	else{
		b[0]=1;
		for(int i=1;i<=n;i++){
			if(i>=3){
				for(int j=a[i]+1;j<=maxx;j++){
					sum=(sum+b[j])%mod;
				}
			}
			for(int j=maxx;j>=0;j--){
				if(b[j]!=0){
					b[j+a[i]]=(b[j+a[i]]+b[j])%mod;
				}
			}
		}
		cout<<sum;
	}
	return 0;
} 
