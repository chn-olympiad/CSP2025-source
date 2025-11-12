#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int mod=998244353;
int n,a[N],ans,w;
int cnt[N],p,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	cnt[0]=1;
	p=1;
	for(int i=1;i<=n;i++){
		while(p<=a[i]){
			sum=(sum+mod-cnt[p])%mod;p++; 
		}
		ans=(ans+sum)%mod;
		for(int j=10001;j>=0;j--){
			if(j)sum=(sum+cnt[j])%mod;
			w=min(10001,j+a[i]);
			cnt[w]=(cnt[w]+cnt[j])%mod;
		}
	}
	printf("%d",ans);
	return 0;
}

