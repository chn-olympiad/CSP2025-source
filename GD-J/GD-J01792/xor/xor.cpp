#include<bits/stdc++.h>
using namespace std;
const int M=5*1e5+10;
int n;
long long k,a[M],ans,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		sum^=a[i];
		if(sum==k)
			ans++,sum=0;
	}
	printf("%lld",ans);
	return 0; 
} 
