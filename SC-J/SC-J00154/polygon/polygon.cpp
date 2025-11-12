#include <bits/stdc++.h>
using namespace std;
long long n,a[5001],b1=1,ans,d[5001],sum[5005];
void as(long long x,long long y){
	if(x==0){
		long long num=0;
		for(long long i=1;i<=y;i++)num+=a[d[i]];
		for(long long i=1;i<=y;i++)if(num<=a[d[i]]*2){
			return;
		}ans++;
		return;
	}
	for(long long i=d[x+1]+1;i<=n-x+1;i++){
		d[x]=i;
		as(x-1,y);
	}
}void ad(int x){
	if(x==0)return;
	for(int i=2;i<=n;i++)sum[i]+=sum[i-1],sum[i]%=998244353;
	ad(x-1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)b1=0;
	}if(b1){
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n;j++)sum[j]=1;
			ad(i);
			ans+=sum[n-i+1];
			ans%=998244353;
		}cout<<ans;
	}else{
		for(long long i=3;i<=n;i++){
			as(i,i);
		}cout<<ans;
	}
	return 0;
}