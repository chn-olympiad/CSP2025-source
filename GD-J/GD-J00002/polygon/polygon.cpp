#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10,mod=998244353;
ll n,a[N]={0},ans=0,sa[N]={0};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sa[i]=sa[i-1]+a[i];
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i-2;j++){
			if(sa[i]-sa[j-1]>2*a[i]){
				ans++;
				ans%=mod;
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
