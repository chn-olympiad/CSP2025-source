#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,p=0,q=0,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]==0) p++;
		if(a[i]==1) q++;
	}
	if(k==0) ans=p+q/2;
	else ans=q;
	printf("%d",ans);
	return 0;
}

