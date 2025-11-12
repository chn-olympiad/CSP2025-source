#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
ll n,m,pv;
vector<ll> v;
bool cmp(ll x,ll y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++) {
		for(ll j=0;j<m;j++) {
			ll x;
			scanf("%lld",&x);
			if(i==0 && j==0) pv=x;
			v.push_back(x);
		}
	}
	sort(v.begin(),v.end(),cmp);
	ll x=0,y=0,idx=0;
	for(;x<n;x++) {
		if(x%2==0) {
			for(y=0;y<m;y++) {
//				cout<<"debug: "<<x+1<<" "<<y+1<<": "<<v[idx]<<"\n";
				if(v[idx]==pv) {
					cout<<x+1<<" "<<y+1;
					return 0;
				}
				idx++;
			}
		}
		else {
			for(y=m-1;y>=0;y--) {
//				cout<<"debug: "<<x+1<<" "<<y+1<<": "<<v[idx]<<"\n";
				if(v[idx]==pv) {
					printf("%lld %lld",x+1,y+1);
					return 0;
				}
				idx++;
			}	
		}
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

*/

// Ô¤¼ÆµÃ·Ö100tps 
