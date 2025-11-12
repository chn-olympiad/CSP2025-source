#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],sum[N],last,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=last;j--){
			if((sum[i]^sum[j])==k){
				ans++;
				last=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0; 
}
