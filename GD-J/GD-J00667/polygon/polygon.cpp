#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,ans;
int a[5010];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<(1<<n);i++){
		int num=0,numx=0,numy=0,sum=i;
		while(sum){
			if(sum&1){
				numx+=a[num];
				numy=max(a[num],numy);
			}
			num++;
			sum>>=1;
		}
		if(numx>numy*2&&num>=3){
			ans++;
			ans%=MOD;
		}
	}
	cout<<ans%MOD;
	return 0;
}
