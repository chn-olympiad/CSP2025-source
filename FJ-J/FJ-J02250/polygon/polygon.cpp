#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e3+5,Mod=998244353;
int n;
int a[N],f[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0,p2=1;
	f[0]=1;
	for(int i=1;i<=n;i++){
		ans=(ans+p2)%Mod;
		for(int j=a[i];j>=0;j--) ans=(ans-f[j]+Mod)%Mod;
		for(int j=5000;j>=a[i];j--) f[j]=(f[j]+f[j-a[i]])%Mod;
		p2=2ll*p2%Mod;
	}
	printf("%d",ans);
	return 0;
}
