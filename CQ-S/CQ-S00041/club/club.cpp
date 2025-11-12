#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,a[5][600005],ans;
struct node{
	int u,num;
	bool operator < (const node &a) const{
		return a.num<num;
	};
};
priority_queue<node> qa,qb,qc;
void solve(){
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[1][i]>>a[2][i]>>a[3][i];
		if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]){
			qa.push({i,a[1][i]-max(a[2][i],a[3][i])});
			ans+=a[1][i];
		}else if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i]){
			qb.push({i,a[2][i]-max(a[1][i],a[3][i])});
			ans+=a[2][i];
		}else{
			qc.push({i,a[3][i]-max(a[1][i],a[2][i])});
			ans+=a[3][i];
		}
	}
	if(qa.size()*2>n){
		while(qa.size()*2>n){
			ans-=qa.top().num;
			qa.pop();
		}
	}else if(qb.size()*2>n){
		while(qb.size()*2>n){
			ans-=qb.top().num;
			qb.pop();
		}
	}else if(qc.size()*2>n){
		while(qc.size()*2>n){
			ans-=qc.top().num;
			qc.pop();
		}
	}
	cout<<ans<<"\n";
	while(!qa.empty()) qa.pop();
	while(!qb.empty()) qb.pop();
	while(!qc.empty()) qc.pop();
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>T;
	while(T--) solve();
	return 0;
}






























//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御海猫不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
//凛御银灰不歪，玩到关服！
