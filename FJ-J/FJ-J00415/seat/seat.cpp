#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,r,rk,h;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++)if(a[i]==r)rk=i-1;
	h=rk/n;
	cout<<h+1<<" ";
	if(h&1)cout<<n-(rk%n)<<'\n';
	else cout<<rk%n+1<<'\n';
	return 0;
}
