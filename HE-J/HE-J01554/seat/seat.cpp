#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100100],ans,num,l,r;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	ans=a[1];
	for(int i=1;i<=n*m;i++)
		if(a[i]>=ans) num++;
	r=num/n; l=num%n;
	if(r%2==1)
	{
		if(l==0) cout<<r<<" "<<n;
		else cout<<r+1<<" "<<n-l+1;
	}
	else
	{
		if(l==0) cout<<r<<" "<<1;
		else cout<<r+1<<" "<<l;
	}
	return 0;
}
