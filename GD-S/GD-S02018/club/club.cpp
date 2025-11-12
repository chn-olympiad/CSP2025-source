#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t,a[100005][5],b[5],cnt[100005],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=b[1]=b[2]=b[3]=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%lld",&a[i][j]);
		for(int i=1;i<=n;i++){
			ll mi1=0,mi2;
			for(int j=1;j<=3;j++)
				if(a[i][j]>mi1){mi1=a[i][j],mi2=j;}
			b[mi2]++,ans+=mi1;
		}
		ll k=0;
		if(b[1]>n/2)k=1;
		else if(b[2]>n/2)k=2;
		else if(b[3]>n/2)k=3;
		if(k==0)
			printf("%lld\n",ans);
		else {
			ll m=0;
			for(int i=1;i<=n;i++){
				ll t=0,t1;
				for(int j=1;j<=3;j++)
					if(a[i][j]>t){t=a[i][j],t1=j;}
				if(t1==k){
					cnt[++m]=1e9;
					for(int j=1;j<=3;j++)
						if(j!=k)cnt[m]=min(cnt[m],t-a[i][j]);
				}
			}
			sort(cnt+1,cnt+m+1);
			for(int i=1;i<=b[k]-n/2;i++)ans-=cnt[i];
			printf("%lld\n",ans); 
		}
	}
	return 0;
} 
