#include<bits/stdc++.h>
using namespace std;
long long n,k,a[16005][15005],num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i][i]);
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			a[j][i]=a[i][j]=a[i-1][j]^a[i][i];
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(a[i][j]==k){
				num++;
				j=i;
				break;
			}
		}
	}
	printf("%lld",num);
	return 0;
}
