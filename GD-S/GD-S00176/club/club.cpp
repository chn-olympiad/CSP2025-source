#include<bits/stdc++.h>
typedef long long ll;
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define mem0(s) memset(s,0,sizeof(s))
#define memf(s) memset(s,0x7f,sizeof(s))
using namespace std;
const int N = 1e6+10;
const ll M = 1e9+10;
struct node{
	ll a1,a2,a3;
}e[N];
ll n,m;
ll a[N][4];
ll kp(node x){
	ll a1=x.a1,a2=x.a2,a3=x.a3;
	ll maxn=max(a1,max(a2,a3));
	if(a1==maxn){
		if(a2>a3) return a1-a2;
		else return a1-a3;
	}
	else if(a2==maxn){
		if(a1>a3) return a2-a1;
		else return a2-a3;
	}
	else{
		if(a1>a2) return a3-a1;
		else return a3-a2;
	}
}
bool cmp(node a,node b){
	return kp(a)>kp(b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
			f(i,1,n){
				scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
				e[i]={a[i][1],a[i][2],a[i][3]};
			}
			sort(e+1,e+n+1,cmp);
			ll cnt1=0,cnt2=0,cnt3=0,ans=0;
			f(i,1,n){
				ll a1=e[i].a1,a2=e[i].a2,a3=e[i].a3;
				if(cnt1==n/2){
					if(cnt2==n/2){
						cnt3++;
						ans+=a3;
					}
					else if(cnt3==n/2){
						cnt2++;
						ans+=a2;
					}
					else if(a2>a3){
						cnt2++;
						ans+=a2;
					}
					else{
						cnt3++;
						ans+=a3;
					}
				}
				else if(cnt2==n/2){
					if(cnt1==n/2){
						cnt3++;
						ans+=a3;
					}
					else if(cnt3==n/2){
						cnt1++;
						ans+=a1;
					}
					else if(a1>a3){
						cnt1++;
						ans+=a1;
					}
					else{
						cnt3++;
						ans+=a3;
					}
				}
				else if(cnt3==n/2){
					if(cnt1==n/2){
						cnt2++;
						ans+=a2;
					}
					else if(cnt2==n/2){
						cnt1++;
						ans+=a1;
					}
					else if(a1>a2){
						cnt1++;
						ans+=a1;
					}
					else{
						cnt2++;
						ans+=a2;
					}
				}
				else{
					ll maxn=max(a1,max(a2,a3));
					if(a1==maxn){
						ans+=a1;
						cnt1++;
					}
					else if(a2==maxn){
						ans+=a2;
						cnt2++;
					}
					else{
						ans+=a3;
						cnt3++;
					}
				}
			}
			printf("%lld\n",ans);
	}
	return 0;
}

