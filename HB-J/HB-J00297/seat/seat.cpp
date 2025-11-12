#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[1005],n,m,p,cnt,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>p;
	a[1]=p;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==p)cnt=i;
	if(cnt<n)cout<<cnt<<" ";
	else cout<<cnt/n+1<<" ";
	if(n%cnt==0) r=1;
	else r=cnt%n;
	cout<<r;
	return 0;
}
