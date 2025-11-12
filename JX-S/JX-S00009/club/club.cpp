#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
int T,n;
struct node{
	ll f,s,t;
};
struct node1{
	ll num,newc;
};
node1 chg[N];
node peo[N];
vector<ll> G[4];
ll ans=0;
bool cmp(node1 a,node1 b){
	return a.newc<b.newc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		memset(chg,0,sizeof(chg));
		for(int i=1;i<=3;i++) G[i].clear();
		for(int i=1;i<=n;i++){
			cin>>peo[i].f>>peo[i].s>>peo[i].t;
			if(max(peo[i].f,max(peo[i].s,peo[i].t))==peo[i].f) G[1].push_back(i);
			else if(max(peo[i].f,max(peo[i].s,peo[i].t))==peo[i].s) G[2].push_back(i);
			else if(max(peo[i].f,max(peo[i].s,peo[i].t))==peo[i].t) G[3].push_back(i);
		}
		bool flag=0;
		int tmp;
		for(int i=1;i<=3;i++){
			if((int)G[i].size()>n/2){
				tmp=i;
				flag=1;
				break;
			}
		}
		if(flag){
			for(int i=0;i<(int)G[1].size();i++){
				ans+=peo[G[1][i]].f;
			}
			for(int i=0;i<(int)G[2].size();i++){
				ans+=peo[G[2][i]].s;
			}
			for(int i=0;i<(int)G[3].size();i++){
				ans+=peo[G[3][i]].t;
			}
			int cnt=0;
			for(int i=0;i<(int)G[tmp].size();i++) chg[++cnt].num=G[tmp][i];
			if(tmp==1){
				for(int i=1;i<=cnt;i++) chg[i].newc=max(peo[chg[i].num].s-peo[chg[i].num].f,peo[chg[i].num].t-peo[chg[i].num].f);
				sort(chg+1,chg+cnt+1,cmp);
			}
			if(tmp==2){
				for(int i=1;i<=cnt;i++) chg[i].newc=max(peo[chg[i].num].f-peo[chg[i].num].s,peo[chg[i].num].t-peo[chg[i].num].s);
				sort(chg+1,chg+cnt+1,cmp);
			}
			if(tmp==3){
				for(int i=1;i<=cnt;i++)	chg[i].newc=max(peo[chg[i].num].s-peo[chg[i].num].t,peo[chg[i].num].f-peo[chg[i].num].t);
				sort(chg+1,chg+cnt+1,cmp);
			}
			for(int i=cnt;i>=1;i--){
				if(i==n/2){
					cout<<ans<<"\n";
					break;
				}
				ans+=chg[i].newc;
			}
		}
		else{
			for(int i=0;i<(int)G[1].size();i++){
				ans+=peo[G[1][i]].f;
			}
			for(int i=0;i<(int)G[2].size();i++){
				ans+=peo[G[2][i]].s;
			}
			for(int i=0;i<(int)G[3].size();i++){
				ans+=peo[G[3][i]].t;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
