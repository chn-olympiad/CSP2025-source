#include <bits/stdc++.h>
using namespace std;
const int N=5010,Mod=998244353;
int a[N],s[N];
long long ans=0,c[N];
long long C(int n,int m){
	return c[n]/(c[n-m]*c[m]%Mod)%Mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	s[0]=0,c[0]=1;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) c[i]=c[i-1]*i%Mod;
	for(int k=3;k<=n;k++){
		for(int i=1;i<=n-k+1;i++){
			if(s[i+k-1]-s[i]+a[i]<=2*a[i+k-1]||i+k-1>n) continue;
			for(int j=i+k-1;j<=n;j++){
				int cha=s[j]-s[i]+a[i]-2*a[j];
				int le=j-i-k+1;
				if(s[j-1]-s[j-le]+a[j-le]<cha) ans=(ans+C(k-2,le))%Mod;
				/*else{
					int cc=s[j]-s[j-le+1]+a[j-le+1]-cha;
					for(int t=j-le;t>=j;t--){
						if(a[j-le+1]-a[t]>cc){
							 ans=(ans+C(k-2,le)-(j-le+1-t))%Mod;
							 break;
						 }
					 }
				 }*/
			}
		}
	}
	cout<<ans+2;
	return 0;
}

