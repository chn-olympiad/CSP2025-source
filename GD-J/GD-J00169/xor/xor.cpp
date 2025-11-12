#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,k,a[N],pre[N],sum,last[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		pre[i]=pre[i-1]^a[i];
		if(a[i]==k){
			sum++;
		}
	}
	
	for(int i=0;i<n;i++){
		last[pre[i]]=i;
		if(pre[i]==k){
			for(int j=0;j<n;j++){
				
				if(j==i){
					continue;
				}
				if(abs(pre[j]-pre[i-1])==k && last[0]<last[k]){
					sum++;
				}
				last[pre[j]]=j;
			}
		}
		last[pre[i]]=i;
	}
	printf("%lld",sum);
	return 0;
}
