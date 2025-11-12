#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll mod=998244353;
ll n,aer;
ll a[5005];
bool k=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) k=0;
	}
	if(k){
		ll sum=1;
		for(ll i=1;i<=n;i++){
			sum*=2;
			sum%=mod;
		}
		sum--;
		sum-=n;
		sum+=mod;
		sum%=mod;
		sum-=(n*(n-1))/2;
		sum+=mod;
		sum%=mod;
		cout<<sum;
	}else{
		sort(a+1,a+n+1);
		for(ll i=0;i<1<<n;i++){
			ll lun=0,cnt=0,sum=0,k=i,mma=0;
			while(k!=0){
				lun++;
				if(k&1){sum+=a[lun];cnt++;}
				k>>=1;
				if(k==0){
					mma=a[lun];
				}
			}
			if(sum>2*mma&&cnt>=3) aer++;
			aer%=mod;
		}
		cout<<aer;
	}
	return 0;
}
