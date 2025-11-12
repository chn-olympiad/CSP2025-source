#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int s[10005];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	int xiaor=s[1];
	sort(s+1,s+1+n*m);
	int p=lower_bound(s+1,s+1+n*m,xiaor)-s-1;
	p=n*m-p;
	int x=(p+n-1)/n;
	p%=n;
	if(p==0)p=n;
	int y;
	if(x%2==1)y=p;
	else y=n-p+1;
	cout<<x<<" "<<y;
	return 0;
}