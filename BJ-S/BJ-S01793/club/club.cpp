#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
class node{
public:
	ll d1,d2,d3;
}num[N];
bool cmp(node x,node y){
	return max(x.d1,max(x.d2,x.d3))>max(y.d1,max(y.d2,y.d3));
}
ll gmx(ll x){
	ll mx=max(num[x].d1,max(num[x].d2,num[x].d3));
	if(mx==num[x].d1) return 1;
	else if(mx==num[x].d2) return 2;
	else return 3;
}
ll cnt[4],n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		cnt[1]=0,cnt[2]=0,cnt[3]=0;
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>num[i].d1>>num[i].d2>>num[i].d3;
		sort(num+1,num+n+1,cmp);
		ll ans=0;	
		for(ll i=1;i<=n;i++){
			cnt[gmx(i)]++;
			//cout<<gmx(i)<<" ";
			ll tmp=0;
			if(cnt[1]<=n/2){
				tmp=max(tmp,num[i].d1);
			} 
			if(cnt[2]<=n/2){ 
				tmp=max(tmp,num[i].d2);
			}
			if(cnt[3]<=n/2){
				 tmp=max(tmp,num[i].d3);
			}
			ans+=tmp;
		}
		//for(ll i=1;i<=n;i++) cout<<num[i].d1<<" "<<num[i].d2<<" "<<num[i].d3<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}
