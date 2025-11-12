#include<bits/stdc++.h>
using namespace std;
struct lhy{
	long long a1,a2,a3,maxn,c;
}a[100005];
long long t,n;
long long b1[100005],b2[100005],b3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		long long cnt1=0,cnt2=0,cnt3=0,ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a1,&a[i].a2,&a[i].a3);
			a[i].maxn=max(max(a[i].a1,a[i].a2),a[i].a3);
			ans+=a[i].maxn;
			if(a[i].a3>=a[i].a1&&a[i].a3>=a[i].a2)b3[++cnt3]=2*a[i].maxn+min(min(a[i].a1,a[i].a2),a[i].a3)-a[i].a1-a[i].a2-a[i].a3;
			else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3)b2[++cnt2]=2*a[i].maxn+min(min(a[i].a1,a[i].a2),a[i].a3)-a[i].a1-a[i].a2-a[i].a3;
			else if(a[i].a1>=a[i].a3&&a[i].a1>=a[i].a2)b1[++cnt1]=2*a[i].maxn+min(min(a[i].a1,a[i].a2),a[i].a3)-a[i].a1-a[i].a2-a[i].a3;
		}
		if(cnt1>n/2){sort(b1+1,b1+cnt1+1);for(int i=1;i<=cnt1-n/2;i++)ans-=b1[i];}
		if(cnt2>n/2){sort(b2+1,b2+cnt2+1);for(int i=1;i<=cnt2-n/2;i++)ans-=b2[i];}
		if(cnt3>n/2){sort(b3+1,b3+cnt3+1);for(int i=1;i<=cnt3-n/2;i++)ans-=b3[i];}
		cout<<ans<<"\n";
	}
	return 0;
}