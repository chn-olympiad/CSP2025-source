#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],t,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){cin>>a[i];sum[i]=sum[i-1]^a[i];}
	for(int i=1;i<=n;i++){
		int j=t;
		while(j<i&&sum[j]!=(sum[i]^k))j++;
		if(j<i)t=j+1,ans++;
	}
	cout<<ans;
	return 0;
}