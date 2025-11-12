#include<bits/stdc++.h>
using namespace std;
long long n,k,l,r,ans,cnt,s,maxn=-1,a[500010],sum[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	l=1,r=1;
	while(r<=n){
		if((sum[r]^sum[l-1])==k){
			++ans;
			l=r+1;
			r=l;
		}
		else{
			++r;
			if(r==n+1){
				r=l+1;
				++l;
			}
		}
	}
	cout<<ans;
	return 0;
}
