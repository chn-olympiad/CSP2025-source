#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a,b,x;
priority_queue<ll> q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>x;
	q.push(x);
	for(ll i=2;i<=n*m;i++){
		cin>>a;
		q.push(a);
	}
	for(ll i=1;i<=n*m;i++){
		if(q.top()==x){
			a=(i-1)/n+1;
			cout<<a<<' ';
			b=i%n;
			if(a&1){
				if(b) cout<<b;
				else cout<<n;
			}else{
				if(b) cout<<n-b+1;
				else cout<<1;
			}
			break;
		}
		q.pop();
	}
	return 0;
}