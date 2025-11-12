#include<bits/stdc++.h>
using namespace std;
long long a[1000060],f,ans,n;
void kesln(long long sum,long long num,long long an,long long mx){
	if(sum>n) return;
	for(int i=sum;i<=n;i++){
		an+=a[i];
		long long ma=mx;
		mx=max(mx,a[i]);
		if(num>=3&&an>mx*2) ans++;
		kesln(i+1,num+1,an,mx);
		an-=a[i];
		mx=ma;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	if(!f){
		
		for(int i=3;i<=n;i++){
			double sum=1;
			for(int j=1;j<=i;j++){
				sum*=(double)(n-j+1);
				sum/=(double)(i-j+1);
				if(sum-(int)sum==0){
					long long u=sum;
					u%=998244353;
					sum=u;
				}
			}
			ans+=(int)sum%998244353;
		}
		
	}
	else{
		kesln(1,1,0,-1);
	}
	cout<<ans;
	return 0;
}
