#include <cstdio>
using namespace std;
const int N = 5e5 + 10;
int n,k,ans;
int a[N],bef[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		bef[i] = a[i] ^ bef[i-1];
		//printf("%d ",bef[i]);
	}
	if (k==1) {
		for (int i=1;i<=n;i++)
			if (a[i]==1) ans++;
	}
	else if (k==0) {
		int nu1=0,nu0=0,n1t0=0;
		for (int i=1;i<=n;i++) {
			if (a[i]==0) nu0++;
			if (a[i]==0 && nu1>0) {
				n1t0 += nu1/2; nu1 = 0;
			}
			if (a[i]==1) nu1++;
		}
		n1t0 += nu1/2;
		ans += nu0 + n1t0;
	}
	else {
		for (int p=0;p<=n;) {
			for (int i=p+1;i<=n;i++) {
				if ((bef[p] ^ bef[i]) == k) {ans++; p=i-1; break;}
			} p++;
		}
	}
	
	printf("%d",ans);
	return 0;
}

