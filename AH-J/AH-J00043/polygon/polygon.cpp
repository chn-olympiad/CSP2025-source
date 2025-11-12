#include <cstdio>
using namespace std;
int n,a[5005],ok[30],ans,mxx;
long long jc[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf ("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);mxx=mxx>a[i]?mxx:a[i];
	}
	if(n==3){
		if(a[0]+a[1]>a[2]&&a[0]+a[2]>a[1]&&a[1]+a[2]>a[0])	printf("1");
		else 												printf("0");
		return 0;
	}
	if(mxx==1){
		jc[0]=1;jc[1]=1;
		for (int i=2;i<=5000;i++)	jc[i]=jc[i-1]*i%998244353;
		long long anss=0;
		for (int i=3;i<=n;i++){
			anss+=jc[n]/(jc[i]*jc[n-i]);anss%=998244353;
		}
		printf ("%lld",anss);return 0;
	}
	while(1){
		ok[n-1]++;int s=n-1,sum=0,mx=0;
		while(s>0&&ok[s]==2){
			ok[s]=0;ok[--s]++;
		}
		if(ok[0]==2)	break;
		for(int i=0;i<n;i++)
			if(ok[i]==1)	sum+=a[i],mx=mx>a[i]?mx:a[i];
		if(sum>2*mx)	ans++;
	}
	printf ("%d",ans);
	return 0;
}
