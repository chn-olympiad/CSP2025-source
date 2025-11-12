#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;
struct node{
	ll x,y,z;
}a[N];
struct node1{
	ll x,ch;
	bool friend operator<(node1 a1,node1 a2){
		return a1.ch<a2.ch;
	}
};
struct node2{
	ll y,ch;
	bool friend operator<(node2 a1,node2 a2){
		return a1.ch<a2.ch;
	}
};
struct node3{
	ll z,ch;
	bool friend operator<(node3 a1,node3 a2){
		return a1.ch<a2.ch;
	}
};
void solve(){
	cin >> n;
	priority_queue<node1> q1;
	priority_queue<node2> q2;
	priority_queue<node3> q3;
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
		ll maxx=max(a[i].x,max(a[i].y,a[i].z));
		if(maxx==a[i].x){
			q1.push({a[i].x,max(a[i].y-a[i].x,a[i].z-a[i].x)});
			ans+=a[i].x;
		}
		else if(maxx==a[i].y){
			q2.push({a[i].y,max(a[i].x-a[i].y,a[i].z-a[i].y)});
			ans+=a[i].y;
		}
		else if(maxx==a[i].z){
			q3.push({a[i].z,max(a[i].y-a[i].z,a[i].x-a[i].z)});
			ans+=a[i].z;
		}
	}
	ll sz1=q1.size(),sz2=q2.size(),sz3=q3.size();
	if(sz1>n/2){
		while(sz1>n/2){
			ans+=q1.top().ch;
			q1.pop();
			sz1--;
		}
	}
	else if(sz2>n/2){
		while(sz2>n/2){
			ans+=q2.top().ch;
			q2.pop();
			sz2--;
		}		
	}
	else if(sz3>n/2){
		while(sz3>n/2){
			ans+=q3.top().ch;
			q3.pop();
			sz3--;
		}			
	}
	cout << ans << "\n";
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
