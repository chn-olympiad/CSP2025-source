#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,m;
int a[N],ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			ans++;
		}
	}
	int j=ans/n+1;
	cout<<j<<' ';
	if(j%2==1)
	{
		cout<<ans%m+1;
	}
	else
	{
		cout<<n-(ans%m);
	}
	return 0;
}
