#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b,ans,s,maxx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	if(n>20){
		for(int i=1;i<=n;i++){
			ans*=2;
			ans=ans%998244353;
		}
		ans=ans-1-n*(n-1)/2-n;
		if(ans<0)ans+=998244353;
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=1<<n;i++){
		b=i,s=0,maxx=0;
		for(int j=1;j<=n;j++){
			if(b%2){
				s+=a[j];
				maxx=a[j];
			}
			b/=2;
		}
		if(s>maxx*2){
			ans++;
			ans=ans%998244353;
		}
	}
	printf("%d",ans);
	return 0;
}