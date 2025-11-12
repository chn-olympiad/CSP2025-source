#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[10000],x,cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	x=a[0];
	sort(a,a+n*m,greater<int>());
	for(int i=0;i<n*m;i++)if(a[i]==x)cnt=i;
	int rol=cnt/n+1;
	cout<<rol<<' ';
	if(rol&1)cout<<cnt%n+1;
	else cout<<n-cnt%n;
	return 0;
}