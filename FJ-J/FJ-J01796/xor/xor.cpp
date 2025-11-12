#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e6;
int sum[N],f[N];
int mp[M];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		sum[i]=sum[i-1]^x;
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(sum[i]==k){
			f[i]=max(f[i],1);
		}
		int t=mp[k^sum[i]];
		if(t){
			f[i]=max(f[i],f[t]+1);
		}
		mp[sum[i]]=i;
	}
	cout<<f[n]<<'\n';
	return 0;
}
