#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1e2+5;
int n,m;
int a[N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	FOR(i,1,n*m) cin>>a[i];
	int b=a[1];
	sort(a+1,a+n*m+1);
	int t=lower_bound(a+1,a+n*m+1,b)-a;
	t=n*m-t+1;
	int c=(t+n-1)/n;
	int r=t%n;
	if(r==0) r=n;
	if(c%2==0) r=n+1-r;
	cout<<c<<" "<<r;
	return 0;
}
