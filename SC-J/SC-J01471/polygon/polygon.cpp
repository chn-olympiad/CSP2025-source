#include <bits/stdc++.h>
using namespace std;

const int N=5005,Mod=998244353;
int n,maxv,a[N],f[N],dp1[N][2],dp2[N][2];
int ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1),maxv=a[n];
	dp1[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=maxv+1;j++)
			dp2[j][0]=dp2[j][1]=0;
		for(int j=0;j<=maxv+1;j++){
			dp2[j][0]=(dp2[j][0]+dp1[j][0])%Mod;
			dp2[j][1]=(dp2[j][1]+dp1[j][1])%Mod;
			f[j]=(dp1[j][0]+dp1[j][1])%Mod;
		}	
		if(2*a[i]+1<=maxv){
			for(int j=a[i];j<=2*a[i];j++)
				dp2[j][0]=(dp2[j][0]+f[j-a[i]])%Mod;
			for(int j=2*a[i]+1;j<=maxv;j++)
				dp2[j][1]=(dp2[j][1]+f[j-a[i]])%Mod;
			for(int j=maxv-a[i]+1;j<=maxv+1;j++)
				dp2[maxv+1][1]=(dp2[maxv+1][1]+f[j])%Mod;
		} else{
			for(int j=a[i];j<=maxv;j++)
				dp2[j][0]=(dp2[j][0]+f[j-a[i]])%Mod;
			for(int j=maxv-a[i]+1;j<=a[i];j++)
				dp2[maxv+1][0]=(dp2[maxv+1][0]+f[j])%Mod;	
			for(int j=a[i]+1;j<=maxv+1;j++)
				dp2[maxv+1][1]=(dp2[maxv+1][1]+f[j])%Mod;	
		}
		for(int j=0;j<=maxv+1;j++)
			dp1[j][0]=dp2[j][0],dp1[j][1]=dp2[j][1];
	}
	for(int i=0;i<=maxv+1;i++)
		ans=(ans+dp1[i][1])%Mod;
	printf("%d",ans);
	return 0;
}