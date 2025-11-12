#include<bits/stdc++.h>
using namespace std;
long long n,m,a[501798],b[501798],f[509817],t,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	//printf("%lld %lld %lld\n",n,m,a[n]);
	for(long long i=1;i<=n;i++){
		scanf("%lld",a+i);
		b[i]=b[i-1]^a[i];
	}
	for(long long i=1;i<=n;i++){
		t=0; 
		for(long long j=1;j<=i;j++){
			long long tt= b[j-1]^b[i];
			if(tt==m){
				t=max(t,f[j-1]+1);
				//printf("%d %d %d %d\n",j,i,tt,t);
			}
		}
		f[i]=max(ans,t);
		ans=max(ans,f[i]);
		//printf("%lld\n",f[i]);
	}
	cout<<ans;
	return 0;
} 
