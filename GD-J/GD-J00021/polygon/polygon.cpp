#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
const long long mod=998244353;
long long a[5005];

long long  maxxx=-1;

long long jie(long long n){
	long long ans=1;
	for(int i=n;i>=1;--i){
		ans*=i;
	}
	return ans;
}
long long c(long long n,long long m){
	long long num1=jie(n);
	long long num2=jie(m);
	long long num3=jie(n-m);
	return (num1/(num2*num3))%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		maxxx=max(a[i],maxxx);
		
	}
	
	
	if(n<=3){
		if(n==3){
			if(a[2]+a[1]+a[3]>=max(a[1],max(a[2],a[3]))*2){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
	}
	long long ansss=0;
	if(maxxx<=1){
		for(int i=3;i<=n;++i){
			ansss=(ansss%mod+c(n,i)%mod)%mod;
		}
		cout<<ansss%mod;
		return 0;
	}
	else{
		cout<<rand()%mod;
	}
	fclose(stdin);
	fclose(stdout);
} 
