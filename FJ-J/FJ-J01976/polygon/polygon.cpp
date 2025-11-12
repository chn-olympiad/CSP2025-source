#include<bits/stdc++.h>
using namespace std;
int a[5001],n,f[25000001]={1};
const long long Mod=998244353;
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int asum=0;
	for(int i=1;i<=n;i++){
		long long sum=0;
		for(int j=a[i]+1;j<=asum;j++){
			sum=(sum+f[j])%Mod;
		}
		ans=(ans+sum)%Mod;
		asum+=a[i];
		for(int j=asum;j>=a[i];j--){
			f[j]=(f[j-a[i]]+f[j])%Mod;
		}
		//printf("%d %d\n",asum,i);
	}
//	for(int i=1;i<=asum;i++)
//		printf("%d ",f[i]);
	cout<<ans;
	return 0;
}//80p
