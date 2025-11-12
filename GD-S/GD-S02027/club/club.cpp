#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll id,w;
};
ll t,n,ans,c[100100],cnt;
node a[100100][5],b[5];
bool cmp(node x,node y){
	return x.w>y.w;
}
bool cmpp(ll x,ll y){
	return x>y;
}
int main(){
	ll i;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1].w,&a[i][2].w,&a[i][3].w);
		a[i][1].id=1; a[i][2].id=2; a[i][3].id=3;
		sort(a[i]+1,a[i]+4,cmp);
	    }
	    for(i=1;i<=3;i++) b[i].w=0,b[i].id=i;
	    for(i=1;i<=n;i++) b[a[i][1].id].w++;
	    sort(b+1,b+1+4,cmp);
	    ans=0;
		for(i=1;i<=n;i++) ans+=a[i][1].w;
		if(b[1].w>n/2){
			cnt=0;
			for(i=1;i<=n;i++)
			if(a[i][1].id==b[1].id)
			c[++cnt]=a[i][1].w-a[i][2].w;
			sort(c+1,c+1+cnt,cmpp);
			while(cnt>n/2){
				ans-=c[cnt];
				cnt--;
			}
		}
		printf("%lld\n",ans);
	} 
}
