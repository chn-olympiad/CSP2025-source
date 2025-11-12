#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll;
ll t,t1,t2,t3;
ll n,ans;
pll a[100010];
ll cha[100010];
priority_queue<ll,vector<ll>,greater<ll>> q[3];
void init(){
	n=ans=0;
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	memset(a,0,sizeof(a));
	memset(cha,0,sizeof(cha));
}
void qmax(int x){
	if(t1>=t2&&t1>=t3)
		a[x]={t1,0};
	else if(t2>=t1&&t2>=t3)
		a[x]={t2,1};
	else if(t3>=t1&&t3>=t2)
		a[x]={t3,2};
}
void qcha(int x){
	if(a[x].first==t1)
		cha[x]=t1-max(t2,t3);
	else if(a[x].first==t2)
		cha[x]=t2-max(t1,t3);
	else if(a[x].first==t3)
		cha[x]=t3-max(t1,t2);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>t1>>t2>>t3;
			qmax(i);
			qcha(i);
		}
		for(int i=1;i<=n;i++){
			ans+=a[i].first;
			q[a[i].second].push(cha[i]);
			if(q[a[i].second].size()>n/2){
				ans-=q[a[i].second].top();
				q[a[i].second].pop();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

