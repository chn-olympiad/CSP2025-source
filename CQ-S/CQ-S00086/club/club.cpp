#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=100005;
ll T;
ll n,ans;

struct node{
	ll id,delta;
}club[4][N];

ll cnt[4];

struct qwq{
	ll id,val;
}tmp[4];

bool cmp_tmp(qwq a1,qwq a2){
	return a1.val<a2.val;
}

bool cmp1(node a1,node a2){
	return a1.delta<a2.delta;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		for(ll i=1;i<=3;i++)cnt[i]=0;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>tmp[1].val>>tmp[2].val>>tmp[3].val;
			tmp[1].id=1;
			tmp[2].id=2;
			tmp[3].id=3;
			sort(tmp+1,tmp+4,cmp_tmp);
			ll want=tmp[3].id;
			
			cnt[want]++;
			club[want][cnt[want]].id=i;
			club[want][cnt[want]].delta=tmp[3].val-tmp[2].val;
			ans+=tmp[3].val;
		}
		for(ll check=1;check<=3;check++){
			if(cnt[check]>n/2){//有一个超出了 
				sort(club[check]+1,club[check]+cnt[check]+1,cmp1);
				for(ll i=1;i<=cnt[check]-(n/2);i++){
					ans-=club[check][i].delta;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
