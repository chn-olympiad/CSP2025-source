//GZ-S00080 华东师范大学附属贵阳学校 向耕立
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_N=1e5+10;
typedef struct node{
	ll a,b,c,dp;
}node;
ll T,ans=0;
node a[MAX_N];
ll n;
ll p;
bool cmp(node a,node b){
	if(p==1)return min(a.a-a.c,a.a-a.b)<min(b.a-b.c,b.a-b.b);
	if(p==2)return min(a.b-a.c,a.b-a.a)<min(b.b-b.c,b.b-b.a);
	if(p==3)return min(a.c-a.a,a.c-a.b)<min(b.c-b.a,b.c-b.b);
}
void solve(ll cnt){
	for(ll i=1;i<=n&&cnt>n/2;i++){
		if(a[i].dp==p){
			cnt--;
			//printf("=%lld %lld %lld %lld %lld\n",ans,p,a[i].a,a[i].b,a[i].c);
			if(p==1)ans-=min(a[i].a-a[i].c,a[i].a-a[i].b);
			if(p==2)ans-=min(a[i].b-a[i].c,a[i].b-a[i].a);
			if(p==3)ans-=min(a[i].c-a[i].a,a[i].c-a[i].b);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>T;
	while(T--){
		scanf("%d",&n);
		a[0].dp=0;
		ll cnt1=0,cnt2=0,cnt3=0;
		ans=0;
		for(ll i=1,now;i<=n;i++){
			scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			now=max(a[i].a,max(a[i].b,a[i].c));
			ans+=now;
			if(a[i].a==now)a[i].dp=1,cnt1++;
			else if(a[i].b==now)a[i].dp=2,cnt2++;
			else if(a[i].c==now)a[i].dp=3,cnt3++;
		}
		//printf("%lld %lld %lld---\n",cnt1,cnt2,cnt3);
		if(cnt1>n/2){
			p=1;
			sort(a+1,a+1+n,cmp);
			solve(cnt1);
		}else if(cnt2>n/2){
			p=2;
			sort(a+1,a+1+n,cmp);
			solve(cnt2);
		}else if(cnt3>n/2){
			p=3;
			sort(a+1,a+1+n,cmp);
			solve(cnt3);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}