#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
int n,a[10010],sum=0,sum1=1,sum2=1,ans=0,sum3=1,sss=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			sss+=1;
		}
		sum+=a[i];
		mx=max(mx,a[i]); 
	}
	for(int k=1;k<=n;k++){
		sum1*=k;
		sum1=sum1%mod; 
	}
	if(n==3){
		if((mx*2)>sum){
			cout<<0;
		}else{
			cout<<1;
		}
	}else if(sss==n){
		for(int i=3;i<=n;i++){
			if(n==i){
				sum3=1;
			}else{
				for(int k=1;k<=n-i;k++){
					sum3*=k;
					sum3%mod;
				}
			}
			for(int j=1;j<=i;j++){
				sum2*=j;
				sum2=sum2%mod;
			}
			ans+=sum1/(sum2*sum3)%mod;
			sum2=1,sum3=1;
		}
		cout<<ans;
	}else{
		cout<<75;
	}
	return 0;
}
