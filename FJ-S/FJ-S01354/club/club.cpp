#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define R(a,b,c) for(ll a=b;a<=c;a++)
#define E(a,b,c) for(ll a=b;a>=c;a--)
using namespace std;
ll a[100025][3];
vector<int> t0;
vector<int> t1;
vector<int> t2;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		R(i,1,n)cin>>a[i][0]>>a[i][1]>>a[i][2];
		t0.clear();
		t1.clear();
		t2.clear();
		ll sum=0;
		R(i,1,n){
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2])t0.push_back(i);
			else if(a[i][1]>a[i][0]&&a[i][1]>a[i][2])t1.push_back(i);
			else t2.push_back(i);
			sum+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		ll tt=n/2;
		if(t1.size()<=tt&&t2.size()<=tt&&t0.size()<=tt){
			cout<<sum<<'\n';
			continue;
		}
		if(t1.size()>tt)swap(t1,t0);
		if(t2.size()>tt)swap(t2,t0);
		vector<ll> ts;
		for(auto v:t0) {
			if(a[v][0]<a[v][1])swap(a[v][0],a[v][1]);
			if(a[v][1]<a[v][2])swap(a[v][1],a[v][2]);
			if(a[v][0]<a[v][1])swap(a[v][0],a[v][1]);
			ts.push_back(a[v][1]-a[v][0]);
		}
		sort(ts.begin(),ts.end(),greater<ll>());
		ll nw=t0.size();
		ll p=0;
		while(nw>tt){
			sum+=ts[p];
			p++;
			nw--;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
//14:45
