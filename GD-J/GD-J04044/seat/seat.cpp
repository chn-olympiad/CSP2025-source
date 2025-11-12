#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
int a[105];

bool cmp(int a,int b)
{
	return a>b;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++) cin>>a[i];
	
	int t=a[1],i=0;
	sort(a+1,a+n*m+1,cmp);
	while(a[++i]!=t);
	t=i;
	
	cout<<(t-1)/n+1<<' ';
	
	if(((t-1)/n+1)&1) cout<<(t-1)%n+1;
	else cout<<n-t%n+1;
	

	return 0;
}

