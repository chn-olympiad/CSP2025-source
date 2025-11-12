#include<bits/stdc++.h>
using namespace std;
const long long m=998244353;
long long n,a[5005],f[5000*5000+5],sum,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=a[i];j--){
			f[j]+=f[j-a[i]];
			if(i>=3){
				ans+=f[j-a[i]];
				ans%=m;
			} 
			
			f[j]%=m;
		}
	}
	cout<<ans;
	return 0;
}
