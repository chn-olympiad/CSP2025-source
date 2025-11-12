#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans[500005]={};
bool fg=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			fg=1;
		}
	}
	if(!fg){
		printf("%d",n/2);
		return 0;
	}
	for(int i=1;i<=n;i++){
		int now=a[i],sum=ans[i-1];
		for(int j=i+1;j<=n;++j){
			if(now==k){
				sum++;
				now=a[j];
				ans[j-1]=max(max(ans[j-1],ans[j-2]),sum);
				continue;
			}
			now^=a[j];
			ans[j-1]=max(max(ans[j-1],ans[j-2]),sum);
		}
		if(now==k){
			sum++;
		}
		ans[n]=max(max(ans[n],ans[n-1]),sum);
	}
	printf("%d\n",ans[n]);
	return 0;
}
