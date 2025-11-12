#include<bits/stdc++.h>
using namespace std;
long long n,k,a[150000],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
	long long maxn=-999999,total=0;
		for(long long j=i;j<=n;j++){
			//if(j-i>=2){
				if(maxn<=a[j])maxn=a[j];
				total=total+a[j];
				if(total>(2*maxn)){
					ans++;
					ans=ans%998244353;
					//cout<<a[i]<<" "<<a[j];
					//cout<<endl;
				}
			//}
			
			
		}
		
	}
	cout<<ans;
	return 0;
}
