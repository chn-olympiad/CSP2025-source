#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long ans;int n;
long long a[5005],b[5005],K;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		for(int i=1;i<=n;i++) cin>>a[i];
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3])) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		if(i==n){
			ans+=1;
			break;
		}
		K=1;
		for(int j=i;j<=n;j++) b[j]=j;
		for(int j=2;j<=n-i;j++){
			for(int k=n;k>=2;k--){
				if(b[k]%j==0){
					b[k]/=j;
					break;
				}
				if(j%b[k]==0) j/=b[k];
			}
		}
		for(int j=i+1;j<=n;j++){
			K*=b[j];
			K%=MOD;
		}
		ans+=K;
		ans%=MOD;
		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
