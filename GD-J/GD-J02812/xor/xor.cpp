#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500002],sum=0,cnt=0,maxx=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int l=1,r=1;
	while(r<=n){
		sum+=a[r];
		if(sum==k){
			cnt=r-l+1;
			maxx=max(cnt,maxx);
			l=r+1;
			r=l;
			sum=0;
		}
		else if(sum<k){
			r++;
		}
		else {
			l=r;
		}
	}
	printf("%d",maxx);
	return 0;
}
