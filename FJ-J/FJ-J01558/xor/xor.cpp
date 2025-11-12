#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500008],sum,f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=n-i;j>=0;j--){
			f=0;
			if(a[j]==-1){
				f++;
			}
			if(a[j]==k){
				sum++;
				a[j]=-1;
			}
			if(a[j+1]>=0&&a[j]>=0){
				a[j]=a[j]^a[j+1];
			}
			else{
				a[j]=-1;
			}
		}
		if(f==n-1){
			break;
		}
	}
	printf("%lld",sum);
	return 0;
}
