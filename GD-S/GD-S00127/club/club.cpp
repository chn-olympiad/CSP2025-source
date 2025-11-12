#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+7;
ll t,n;
struct node{
	ll a,b,c;
}p[N];
vector<ll>A,B,C;
ll v[N],cnt,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		A.clear(),B.clear(),C.clear();
		ans=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].c);
			if(p[i].a>=p[i].b&&p[i].a>=p[i].c)A.push_back(i),ans+=p[i].a;
			else if(p[i].b>=p[i].a&&p[i].b>=p[i].c)B.push_back(i),ans+=p[i].b;
			else C.push_back(i),ans+=p[i].c;
		}
		ll a=A.size(),b=B.size(),c=C.size();
		if(a>n/2){
			cnt=0;
			for(int i=0;i<a;i++)
				v[++cnt]=min(p[A[i]].a-p[A[i]].b,p[A[i]].a-p[A[i]].c);
			sort(v+1,v+1+cnt);
			for(int i=1;i<=a-n/2;i++)
				ans-=v[i];
		}
		else if(b>n/2){
			cnt=0;
			for(int i=0;i<b;i++)
				v[++cnt]=min(p[B[i]].b-p[B[i]].c,p[B[i]].b-p[B[i]].a);
			sort(v+1,v+1+cnt);
			for(int i=1;i<=b-n/2;i++)
				ans-=v[i];
		}
		else if(c>n/2){
			cnt=0;
			for(int i=0;i<c;i++)
				v[++cnt]=min(p[C[i]].c-p[C[i]].b,p[C[i]].c-p[C[i]].a);
			sort(v+1,v+1+cnt);
			for(int i=1;i<=c-n/2;i++)
				ans-=v[i];
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
