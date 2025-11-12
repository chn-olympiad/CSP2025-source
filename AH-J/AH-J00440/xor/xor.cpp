#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n,k,a[500005],sum[500005],ans;
bool f[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			if(f[j+1]==1){
				break;
			}
			if((sum[i]^sum[j])==k){
				ans++;
				for(int x=j+1;x<=i;x++){
					f[x]=1;
				}
				break;
			}
		}
	}
	cout<<ans;
    return 0;
}
