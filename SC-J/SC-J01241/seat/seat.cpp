#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,cnt,c,r;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==ans)
		{
			cnt=i;
			break;
		}
	if(cnt%n==0)
		c=cnt/n;
	else
		c=cnt/n+1;
	if(c%2==1)
	{
		if(cnt%n!=0)
			r=cnt%n;
		else
			r=n;
	}
	else
		r=n-cnt%n+1;
	cout<<c<<" "<<r;
	return 0;
}