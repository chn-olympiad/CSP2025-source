#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	int start=1;
	for(int r=1;r<=n;r++){
		for(int l=start;l<=r;l++){
			int s=sum[r]^sum[l-1];
			if(s==k){
				ans++;
				start=r+1;
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
