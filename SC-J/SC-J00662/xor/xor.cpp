#include<bits/stdc++.h>
using namespace std;
int f[500005],a[500005],n;
long long int k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	f[1] = a[1]==k? 1:0;f[0] = -99999;
	for(int i=2;i<=n;i++){
		f[i] = f[i-1];
		long long int temp=a[i];
		if(temp == k)f[i]++;
		for(int j=i-1;j>=1;j--){
			temp = temp^a[j];
			if(temp == k){
				f[i] = max(f[i],f[j-1]+1);
				break;
			}
		}
	}
	printf("%d",f[n]);
	return 0;
}
