#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int a[N],b[N],sum[4],n,ans=0,s[N],cnt=0,T;
void check(int op){
	for(int i=1;i<=n;++i) if(a[i]==op) s[++cnt]=b[i];
	sort(s+1,s+cnt+1);
	for(int i=1;i<=cnt-n/2;++i) ans-=s[i];
}signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		sum[1]=sum[2]=sum[3]=cnt=ans=0;
		for(int i=1;i<=n;++i) {
			int a1,a2,a3;
			scanf("%lld%lld%lld",&a1,&a2,&a3);
			int max1=max(a1,max(a2,a3));
			if(a1==max1) a[i]=1,b[i]=max1-max(a2,a3),sum[1]++;
			else if(a2==max1) a[i]=2,b[i]=max1-max(a1,a3),sum[2]++;
			else if(a3==max1) a[i]=3,b[i]=max1-max(a1,a2),sum[3]++;
			ans+=max1;
		}if(sum[1]>n/2) check(1);
		if(sum[2]>n/2) check(2);
		if(sum[3]>n/2) check(3);
		printf("%lld\n",ans);
	}return 0;
} 
