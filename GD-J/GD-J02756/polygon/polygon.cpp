#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5001],cnt[5001];
long long jie(long long x){
	if(x==1){
		return 1;
	}
	return x*jie(x-1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cnt[i]=cnt[i-1]+a[i];
	}
	long long sum=0;
	for(int i=3;i<=n;i++){
		long long zuhe=1;
		for(int j=i;j<=n;j++){
			zuhe*=j;
		}
		zuhe/=jie(i);
		sum+=zuhe;
	}
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(cnt[k]-cnt[j]+cnt[i]<=(a[k]*2)){
					sum--; 
				}
			}
		}
	}
	cout<<(sum%mod);
	return 0;
} 
