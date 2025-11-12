#include <bits/stdc++.h>
using namespace std;
long long n,k,a,sum[500005],l=-1,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (long long i=0;i<n;i++){
		cin>>a;
		if (i==0)
		  sum[i]=a;
		else
		  sum[i]=a^sum[i-1];
	}
	for (long long i=0;i<n;i++){
		bool flag=1;
		for (long long j=i-1;j>=max(l,0ll);j--){
			if ((sum[i]^sum[j])==k){
				l=i;
				flag=0;
				ans++;
				break;
			}
		}
		if (flag&&sum[i]==k){
			if (0>l){
			    l=i;
			    ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
