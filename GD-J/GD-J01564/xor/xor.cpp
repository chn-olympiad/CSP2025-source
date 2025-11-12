#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],sum[500010],x;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
		cout<<sum[i]<<" ";
	}
	cout<<endl;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			x=sum[j]-sum[i-1];
			if(x==k){
				ans++;
				//cout<<i<<" "<<j<<endl;
				i=j+1;j=j+1;	
			}
		}
	}
	cout<<ans;
	return 0;
} 
