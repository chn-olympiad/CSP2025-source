#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
int a[1100];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int ans=a[1];
	int cnt;
	sort(a+1,a+1+n*m,cmp);
	int lei=1,hang=1;
	bool f=false;
	for(int i=1;i<n*m;i++)
	{
		if(a[i]==ans) break;
		if(f==false) hang++;
		if(f==true) hang--;
		if(i%n==0)
		{
			lei++;
			if(f==false)
			{
				f=true;
				hang--;
			}
			else
			{
				f=false;
				hang++;
			}
		}
	}
	if(hang>n) hang=n;
	cout<<lei<<' '<<hang;
	return 0; 
}
