#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],sum[N],f[N];
map<int,int> lst;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)  scanf("%d",a+i),sum[i]=sum[i-1]^a[i];
	lst[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(lst.count(sum[i]^k))
			f[i]=max(f[i],f[lst[sum[i]^k]]+1);
		lst[sum[i]]=i;
	}
	printf("%d",f[n]);
	return 0;
}
