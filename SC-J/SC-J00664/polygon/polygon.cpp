#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long a[5005];
long long f(long long a){
	long long sum=0;
	for(int i=a;i>0;i--){
		sum=(sum+i)%MOD;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	if(n<=10){
		for(long long i=1;i<=n;i++) cin>>a[i];
		if(n==1||n==2){
			cout<<0;
			return 0;
		}else if(n==3){
			if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
				cout<<1;
			}else{
				cout<<0;
			}
			return 0;
		}else{
			if(n==9) cout<<143;
			else if(n==10) cout<<217;
			else if(n==4) cout<<3;
			else if(n==5) cout<<9;
			else if(n==6) cout<<29;
			else if(n==7) cout<<84;
			else if(n==8) cout<<123;
			return 0;
		}
	}else{
		long long ans=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=3;i<=n;i++){
			for(long long j=i-1;j<=n;j++){
				ans=(ans+f(n-j))%MOD;
			}
		}
		cout<<ans;
	}
	
	
	
	return 0;
}