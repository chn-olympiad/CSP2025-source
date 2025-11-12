#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10,mod=998244353;
long long a[N],n,k,b[N],xb1[N],xb2[N],xb=1,maxx,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		maxx=max(maxx,a[i]);
	}
	maxx*=2;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++){
			if(b[i]-b[j-1]>maxx){
				cout<<j<<" "<<i<<endl;
				ans=(ans+1)%mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
