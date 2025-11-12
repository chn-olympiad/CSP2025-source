#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x,y,m[107];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i = 1;i<=n;i++){
		cin>>m[i];y = max(y,m[i]);
	}
	x = m[1]+m[2]+m[3];y*=2;
	if(x>y)cout<<"1";
	else cout<<"0";
	
	return 0;
}
