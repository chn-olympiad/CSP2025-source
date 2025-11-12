#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
vector<ll> q0,q1,q2;
ll T,n,i,j,a[N][4],ans,ct[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ans=0,ct[0]=0,ct[1]=0,ct[2]=0,q0.clear(),q1.clear(),q2.clear();
		scanf("%lld",&n);
		for(i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		for(i=1;i<=n;i++){
			ll temp = max(a[i][0],max(a[i][1],a[i][2]));
			ans += temp;
			if(temp==a[i][0]) ct[0]++,q0.push_back(a[i][0]-max(a[i][1],a[i][2]));
			else if(temp==a[i][1]) ct[1]++,q1.push_back(a[i][1]-max(a[i][0],a[i][2]));
			else ct[2]++,q2.push_back(a[i][2]-max(a[i][0],a[i][1]));
		}
		sort(q0.begin(),q0.end()),sort(q1.begin(),q1.end()),sort(q2.begin(),q2.end());
		if(ct[0]>n/2){
			for(i=0;i<ct[0]-n/2;i++) ans-=q0[i]; 
		}
		else if(ct[1]>n/2){
			for(i=0;i<ct[1]-n/2;i++) ans-=q1[i]; 
		} 
		else if(ct[2]>n/2){
			for(i=0;i<ct[2]-n/2;i++) ans-=q2[i]; 
		}
		printf("%lld\n",ans); 
	}
	return 0;
}
