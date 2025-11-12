#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,cnt;
const int p=998244353;
int d[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int h=1<<n;
	if(h<0) h=1e9;	
	for(int i=1;i<=h&&((double)clock()/CLOCKS_PER_SEC<=0.995);i++){
		int cnt=0,k=i,cc=0,maxn=-1,g=0;
		while(k){
			d[++cnt]=k%2;
			if(d[cnt]==1) ++g;
			k/=2;
		}
		if(g<3){
			continue;
		}
		for(int j=1;j<=cnt;j++){
			if(d[j]){
				cc+=a[j];
				maxn=max(maxn,a[j]);
			}
		}
		if(cc>maxn*2){
			ans++;
			ans%=p;
		}
	}
	printf("%d",ans);
	return 0;
}
