#include <bits/stdc++.h>
using namespace std;
int n,k,t;
int a[500005],pre[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		if(num==k){
			num=a[i]; ans++;
		}else num^=a[i];
	if(num==k) ans++;
//	for(int i=1;i<=n;i++)
//		pre[i]=pre[i-1]^a[i];
//	t=pre[n]^k;
	printf("%d\n",ans);
	return 0;
}
