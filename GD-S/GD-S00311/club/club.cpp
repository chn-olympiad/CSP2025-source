#include <iostream>
#include <queue>
#define int long long
using namespace std;
int ans,t,n,cnt1,cnt2,cnt3;
struct P1{
	int a,b,c;
	bool operator <(const P1 &x) const{
		return (a-max(b,c))>(x.a-max(x.b,x.c));
	}
};
struct P2{
	int a,b,c;
	bool operator <(const P2 &x) const{
		return (b-max(a,c)>x.b-max(x.a,x.c));
	}
};
struct P3{
	int a,b,c;
	bool operator <(const P3 &x) const{
		return (c-max(a,b))>(x.c-max(x.a,x.b));
	}
};
priority_queue<P1> q1;
priority_queue<P2> q2;
priority_queue<P3> q3;
void init(){
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
	cnt1=cnt2=cnt3=ans=0; 
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		init();
		scanf("%lld",&n);
		for(int i=1,a,b,c;i<=n;i++){
			scanf("%lld%lld%lld",&a,&b,&c);
			int w1=a,w2=b,w3=c;
			if(cnt1==n/2) w1-=q1.top().a-max(q1.top().b,q1.top().c);
			if(cnt2==n/2) w2-=q2.top().b-max(q2.top().a,q2.top().c);
			if(cnt3==n/2) w3-=q3.top().c-max(q3.top().a,q3.top().b);
			int k=max(w1,max(w2,w3));
			ans+=k;
			if(k==w1){
				if(cnt1==n/2) {
					if(q1.top().b>q1.top().c) q2.push({q1.top().a,q1.top().b,q1.top().c}),cnt2++;
					else q3.push({q1.top().a,q1.top().b,q1.top().c}),cnt3++;
					q1.pop();
					cnt1--;
				}
				q1.push({a,b,c});
				cnt1++;
			}
			else if(k==w2){
				if(cnt2==n/2) {
					if(q2.top().a>q2.top().c) q1.push({q2.top().a,q2.top().b,q2.top().c}),cnt1++;
					else q3.push({q2.top().a,q2.top().b,q2.top().c}),cnt3++;
					q2.pop();
					cnt2--;
				}
				q2.push({a,b,c});
				cnt2++;
			}
			else if(k==w3){
				if(cnt3==n/2) {
					if(q3.top().a>q3.top().b) q1.push({q3.top().a,q3.top().b,q3.top().c}),cnt1++;
					else q2.push({q3.top().a,q3.top().b,q3.top().c}),cnt2++;
					q3.pop();
					cnt3--;
				}
				q3.push({a,b,c});
				cnt3++;
			}
		}
		printf("%lld\n",ans);
	}
} 
