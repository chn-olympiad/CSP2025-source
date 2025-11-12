#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
const long long p=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
 	cin>>n;
 	if(n<=20){
 		long long ans=0;
 		for(int i=1;i<=n;i++)cin>>a[i];
 		for(int i=1;i<=pow(2,n);i++){
 			long long xb=0,m=0,num=0,max_=0;
 			for(int j=i;j>0;j/=2){
 				xb++;
 				if(j%2==1){
 					m++;
 					num+=a[xb];
 					max_=max(max_,a[xb]);
				}
			}
			if(m>=3&&num>2*max_)ans++;
		}
		cout<<ans;
	}else{
		long long ans=1;
 		for(int i=1;i<=n;i++)cin>>a[i];
 		for(int i=1;i<=n;i++)ans=(2*ans)%p;
 		ans=(ans+p-n*(n-1)/2-n-1);
 		cout<<ans%p;
	}
	return 0;
} 
//100 + 100 + 30 + 64 = 294 ?
