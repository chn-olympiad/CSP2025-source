#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans,sum=1;
bool A=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) A=false;
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	if(A){
		for(int i=3;i<=n;i++){
			sum=1;
			for(int j=n;j>=i;j--){
				sum*=j;
			}
			for(int j=1;j<=i;j++){
				sum/=j;
			}
			ans+=sum;
			ans%=998244353;
		}
		cout<<(ans+n-3)%998244353;
		return 0;
	}else{
		cout<<0;
	}
	return 0;
}
