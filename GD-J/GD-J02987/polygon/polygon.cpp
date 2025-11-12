#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
bool b=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1)b=0;
	}
	if(b){
		cout<<((1<<n)-(n*n)/2+n/2-2)%998244353;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=0;i<(1<<n);i++){
		long long sum=0,cnt=0,ma,ii=i,j=0;
		while(ii){
			if((ii&1)==1){
				sum+=a[j+1];
				cnt++;
				ma=j;
			}
			ii/=2;
			j++;
		}
		if(cnt<3)continue;
		if(sum>a[ma+1]*2){
			ans++;
			ans%=998244353;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
