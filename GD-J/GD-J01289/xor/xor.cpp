#include<bits/stdc++.h>
using namespace std;
long long n,k,sum[500001],ans,last;
map<long long,long long> m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1,a;i<=n;i++){
		cin>>a,sum[i]=sum[i-1]^a;
		if(sum[m[k^sum[i]]]^sum[i]==k&&m[k^sum[i]]>=last) ans++,last=i;
		m[sum[i]]=i;
	}
	cout<<ans;
	return 0;
}
