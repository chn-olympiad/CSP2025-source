#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[2005],s,r=1,c=1,t=1;
bool f=true;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==s)cout<<c<<' '<<r,exit(0);
		if(f)r++;
		else r--;
		if(f&&r>n)r=n,f^=1,c++;
		if(!f&&r<1)r=1,f^=1,c++;
	}
	return 0;
}

