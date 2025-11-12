#include<bits/stdc++.h> 
using namespace std;
long long n;
long long a[5005];
long long ans;
const long long mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=0;i<=(1<<n)-1;i++){
		long long sum=0,last,num=0;
		for(int j=n-1;j>=1;j--){
			if(i&(1<<j)){
				sum+=a[j+1];
				last=a[j+1];
				num++;
			}
		}
		if(sum>last*2&&num>=3){
			ans++;
			ans%=mod;
		}
	}
	cout<<ans-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
