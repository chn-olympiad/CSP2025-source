#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5010],b[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0; b[0]=1;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	b[a[1]]++; b[a[2]]++; b[a[1]+a[2]]++;
	for(int i=3; i<=n; i++){
		for(int j=5001; j>a[i]; j--)
			ans=(ans+b[j])%mod;
		for(int j=5001; j>=0; j--)
			b[min(j+a[i],5001)]=(b[min(j+a[i],5001)]+b[j])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
