#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],t; 
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	t=a[1];
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			cout<<(i-1)/n+1<<" ";
			if((i-1)/n+1%2==1) cout<<n-i%n;
			else cout<<n-(i+1)%n;
			break;
		}
	}
	return 0;
} 
