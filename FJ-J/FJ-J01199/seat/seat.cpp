#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sc[105];
ll n,m;
ll flag,key;
ll ans1,ans2;

ll fnd(){
	for(ll i=1;i<=n*m;i++)
		if(sc[i]==key)
			return i;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)
		cin>>sc[i];
	key=sc[1];
	sort(sc+1,sc+n*m+1,greater<ll>());
	flag=fnd();
	ans1=flag%m==0?flag/m:flag/m+1;
	ans2=flag%m==0?n:flag%m;
	if(ans1%2==0)ans2=n-ans2+1;
	cout<<ans1<<' '<<ans2;
	
	return 0;
}
