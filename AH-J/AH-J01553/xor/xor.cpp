#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,cnt=0,a[100005],sum[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				cnt++;
				cout<<i<<" "<<j<<endl;
				i=j;
			}
		}
	}
	cout<<cnt;
	return 0;
}
