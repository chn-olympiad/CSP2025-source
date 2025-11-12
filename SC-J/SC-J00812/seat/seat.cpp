#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			r=i;
			break;
		}
	}
	if(r%n==0) cout<<r/n<<' ';
	else cout<<r/n+1<<' ';
	int l=r%(2*n);
	if(l==0) cout<<1;
	else if(l==n) cout<<n;
	else if(l<n) cout<<l;
	else if(l>n) cout<<n-(l-n)+1;
	return 0;
}