#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
ll t,n,cnt[3];
struct Node{
	ll d,id;
}a[3];
bool cmp(Node a,Node b){
	return a.d>b.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		cnt[0]=cnt[1]=cnt[2]=0;
		priority_queue<ll> q[3];
		for(ll i=1;i<=n;i++){
			for(ll j=0;j<3;j++){
				cin>>a[j].d;
				a[j].id=j;
			}
			sort(a,a+3,cmp);
			ans+=a[0].d;
			for(ll j=2;j>=1;j--){
				a[j].d-=a[j-1].d;
			}
			if(cnt[a[0].id]>=n/2){
				if(a[1].d<q[a[0].id].top()){
					ans+=q[a[0].id].top();
					q[a[0].id].pop();
					q[a[0].id].push(a[1].d);
				}else{
					ans+=a[1].d;
				}
			}else{
				cnt[a[0].id]++;
				q[a[0].id].push(a[1].d);
			}
		}
		cout<<ans<<"\n";
	} 
} 


