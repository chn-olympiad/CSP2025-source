#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int MOD=998244353;
int n,a[N];
long long sum[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
	
	for(int i=3;i<=n;i++){
		long long x=sum[i];
		if(x<=a[i]*2) continue;
		ans++;
		ans%=MOD;
		long long z=1,k=i;
		while(x-sum[k-1]<=a[i]*2) k--;
		if(k==1) continue;
		ans+=k-1;
		for(int j=3;j<=k+1;j++){
			for(int y=1;y<j-2;y++){
				for(int b=2;b<=y;b++) z*=b;
			}
			ans+=z;
		}
		ans%=MOD;
		int c=i-2,d=a[i];
		while(c>0){
			k=c;
			while(sum[k]>d) k--,ans++;
			k++;
			c=k-2,d-=k;		
		}
		ans%=MOD;
	}
	printf("%d",ans%MOD);
	return 0;
}
