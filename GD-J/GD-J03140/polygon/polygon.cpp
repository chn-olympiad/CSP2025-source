#include<bits/stdc++.h>
using namespace std;
int n,a[20001],cnt,maxx,x;
long long q,w,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){
		for(int i=3;i<=n;i++){
			q=w=1;
			for(int j=0;j<i;j++){
				w*=n-j;
				w/=i-j;
				w%=998244353;
			}
			ans+=w%998244353;
			ans%=998244353;
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=0;i<(1<<n);i++){
		cnt=maxx=x=0;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				x++;
				cnt+=a[j];
				maxx=max(maxx,a[j]);
			}
		}
		if(cnt>maxx*2&&x>=3){
			ans++;
			ans%=998244353;
		}
	}
	printf("%lld",ans);
	return 0;
}
