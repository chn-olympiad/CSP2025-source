#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,sum;
long long a[500005];
int main(){
	freopen("xor.out","w",stdout);
	freopen("xor.in" ,"r",stdin );
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum=sum^a[i];
		if(sum==k){
			sum=0;
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
//非正解，t5就错 
