#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
int n;
const int N=1e5+10;
ll a[N][5];
ll ans,A,B,C;
#define pii pair<ll,int>
priority_queue<pii>q1;
priority_queue<pii>q2;
priority_queue<pii>q3;
void solve(){
	while(!q1.empty())q1.pop();
	while(!q2.empty())q2.pop();
	while(!q3.empty())q3.pop();
	ans=0;A=B=C=0;
	cin>>n;
	For(i,1,n)For(j,1,3)cin>>a[i][j];
	For(i,1,n){
		ll mx=max(max(a[i][1],a[i][2]),a[i][3]);
		ll mx2=-1,pos=0;ans+=mx;
		if(mx==a[i][1]){
			A++;mx2=max(a[i][2],a[i][3]);
			if(a[i][2]==mx2)pos=2;
			else pos=3;
			q1.push(make_pair(mx2-mx,pos));
		}
		else if(mx==a[i][2]){
			B++;mx2=max(a[i][1],a[i][3]);
			if(a[i][1]==mx2)pos=1;
			else pos=3;
			q2.push(make_pair(mx2-mx,pos));
		}
		else{
			C++;mx2=max(a[i][1],a[i][2]);
			if(a[i][2]==mx2)pos=2;
			else pos=1;
			q3.push(make_pair(mx2-mx,pos));
		}
//		cout<<A<<" "<<B<<" "<<C<<"\n";
		while(A>(n/2)){
			ll d=q1.top().first;
			ll p=q1.top().second;
			q1.pop();
			ans+=d;A--;
			if(p==2)B++;
			else C++;
		}
		while(B>(n/2)){
			ll d=q2.top().first;
			ll p=q2.top().second;
			q2.pop();
			ans+=d;B--;
			if(p==1)A++;
			else C++;
		}
		while(C>(n/2)){
			ll d=q3.top().first;
			ll p=q3.top().second;
			q3.pop();
			ans+=d;C--;
			if(p==1)A++;
			else B++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}
