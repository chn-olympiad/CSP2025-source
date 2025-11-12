#include<bits/stdc++.h>
using namespace std;
namespace leo {
  const int Mod=998244353;
  int n,maxx,ans;
  int a[10005],b[10005];
  int quickPower(int a,int b) {
    if(b==0)
      return 1;
    int t=quickPower(a,b>>1);
    t=(1ll*t*t)%Mod;
    if(b%2)
      t=(1ll*t*a)%Mod;
    return t;
  }
  void dfs(int k,int chosen=0) {
    if(k>n) {
      if(chosen>=3) {
        int maxx=0,sum=0;
        for(int i=1;i<=n;i++)
          if(b[i]) {
            maxx=max(maxx,a[i]);
            sum+=a[i];
		  }
		if(sum>maxx*2) {
		  ans++;
		  ans%=Mod;
		}
	  }
	  return;
	}
	dfs(k+1,chosen);
	b[k]=1;
	dfs(k+1,chosen+1);
	b[k]=0;
  }
  void main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w+",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
      scanf("%d",a+i);
      maxx=max(maxx,a[i]);
	}
    if(maxx==1)
      ans=((((long long)quickPower(2,n)-n-n*(n-1)/2-1)%Mod)+Mod)%Mod;
    else
      dfs(1);
	printf("%d\n",ans);
  }
}
int main() {
  leo::main();
}

