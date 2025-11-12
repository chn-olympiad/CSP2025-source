#include <bits/stdc++.h>
using namespace std;

long long T,n,b[4],c[100010],cnt,ans;
pair<long long,long long> a[100010][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cnt=ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j].first);
				a[i][j].second=j;
			}
			sort(a[i]+1,a[i]+3+1);
			b[a[i][3].second]++;
			ans+=a[i][3].first;
		}
		for(int j=1;j<=3;j++)
		if(b[j]*2>n){
			for(int i=1;i<=n;i++){
//				printf("%lld %lld %lld %lld %lld %lld\n",a[i][1].second,a[i][1].first,a[i][2].second,a[i][2].first,a[i][3].second,a[i][3].first);
				if(a[i][3].second==j){
					c[++cnt]=a[i][3].first-a[i][2].first;
				}
			}
			sort(c+1,c+cnt+1);
			for(int i=1;n/2+i<=cnt;i++){
				ans-=c[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
