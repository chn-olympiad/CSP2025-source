#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005],ans=0,vis[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==k)ans++,vis[i]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			long long b=0;
			bool ok=0;
			for(int k=j;k<=j+i;k++){
				b=(b^a[k]);
				if(vis[k]==1)ok=1;
			}
			if(ok==0&&b==k){
				ans++;
				for(int k=j;k<=j+n;k++)vis[k]=1;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
