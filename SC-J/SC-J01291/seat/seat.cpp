#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n,m,a[110],big=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	for(int i=2;i<=n*m;i++)
		if(a[i]>a[1])
			big++;
	int x=ceil(1.0*big/n),y=(big-1)%n+1;
	if(x%2==0)y=n-y+1;
	cout<<x<<" "<<y;
	return 0;
}
