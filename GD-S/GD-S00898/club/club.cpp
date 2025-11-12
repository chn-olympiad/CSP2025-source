#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct dif{
	int v,s;
};
bool cmp(dif r1,dif r2){
	return r1.v>r2.v;
}
int n,t,a[N],b[N],c[N],cnt1,cnt2,cnt3,ans;
int ct(int bef,bool opt){
	int ret=bef,c1=0,c2=0;
	dif tmp[N];
	for(int i=1;i<=n;i++){
		tmp[i].v=max(b[i]-a[i],c[i]-a[i]);
		if(b[i]-a[i]>c[i]-a[i]) tmp[i].s=1;
		else if(b[i]-a[i]<c[i]-a[i]) tmp[i].s=2;
		else tmp[i].s=3;
	}
	sort(tmp+1,tmp+1+n,cmp);
	for(int i=1;i<=n/2;i++){
		ret+=tmp[i].v;
		if(tmp[i].s==1) c1++;
		else if(tmp[i].s==2) c2++;
	}
	if(opt){
		int cur=n/2+1;
		while(tmp[cur].v>0&&cur<=n&&c1<n/2&&c2<n/2){
			if(tmp[cur].s==1) c1++;
			else if(tmp[cur].s==2) c2++;
			ret+=tmp[cur].v,cur++;
		}
	}
	return ret;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		cnt1=cnt2=cnt3=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]),cnt1+=a[i],cnt2+=b[i],cnt3+=c[i];
		ans=ct(cnt1,1);
		swap(cnt1,cnt2),swap(cnt2,cnt3);
		for(int i=1;i<=n;i++) swap(a[i],b[i]),swap(b[i],c[i]);
		ans=max(ans,ct(cnt1,1));
		swap(cnt1,cnt2),swap(cnt2,cnt3);
		for(int i=1;i<=n;i++) swap(a[i],b[i]),swap(b[i],c[i]);
		ans=max(ans,ct(cnt1,1));
		printf("%lld\n",ans); 
	}
	return 0;
} 
