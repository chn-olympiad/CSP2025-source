#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=300005;
ll T,n,cnt[3],ans,cnt2,q[N];
pair<ll,ll> a[N][3];
bool flag[N];
void solve(){
	cin >>n;
	for(int i=0;i<3;i++)cnt[i]=0;
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			cin >>a[i][j].first;
			a[i][j].second=j;
		}
		sort(a[i],a[i]+3);
		cnt[a[i][2].second]++;
		ans+=a[i][2].first;
	}
//	cout <<ans<<"\n";
	ll k=0,maxn=0;
	for(int i=0;i<3;i++){
		if(cnt[i]>maxn){
			maxn=cnt[i];
			k=i;
		}
	}
	if(cnt[k]>n/2){
		cnt2=0;
		for(int i=1;i<=n;i++){
			if(a[i][2].second==k){
				q[++cnt2]=a[i][2].first-a[i][1].first;
			}
		}
		sort(q+1,q+1+cnt2);
		for(int i=1;i<=cnt2;i++){
			cnt[k]--;
			ans-=q[i];
			if(cnt[k]==n/2)break;
		}
	}
	cout <<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>T;
	while(T--){
		solve();
	}
}
