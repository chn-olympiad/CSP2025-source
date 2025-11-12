#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100005][3],tg[100005],ans,cnt=0;
void solve(){
	cin>>n;
	cnt=(n+2)/3;
	ans=0;
	for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])cnt1++,tg[i]=0;
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])cnt2++,tg[i]=1;
		else cnt3++,tg[i]=2;
		ans+=a[i][tg[i]];
	}
	if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
	}else{
		int u;
		if(cnt1>n/2)u=0;
		if(cnt2>n/2)u=1;
		if(cnt3>n/2)u=2;
		priority_queue<ll> pq;
		for(int i=1;i<=n;i++)if(tg[i]==u){
			if(u==0)pq.push(max(a[i][1],a[i][2])-a[i][u]);
			if(u==1)pq.push(max(a[i][0],a[i][2])-a[i][u]);
			if(u==2)pq.push(max(a[i][0],a[i][1])-a[i][u]);
		}
		while(pq.size()>n/2)ans+=pq.top(),pq.pop();
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
}

