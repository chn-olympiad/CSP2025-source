#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const LL N=1e1+9;
LL n,m,a[N*N],cnt;
LL xsqz(LL x,LL y)
{
	return x/y+(x%y?1:0);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(LL i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>=a[1]) cnt++;
	}
	cout<<xsqz(cnt,n)<<" ";
	if(xsqz(cnt,n)%2) cout<<(cnt%n?cnt%n:n);
	else cout<<(cnt%n?m-cnt%n+1:1);
	return 0;
}