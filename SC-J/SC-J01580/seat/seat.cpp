#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		cnt++;
		if(a[i]==x)
			break;
	}
	int lie=(cnt-1)/n;
	//cout<<cnt<<" "<<lie<<endl;
	if(lie%2==0)
	{
		cout<<lie+1<<" ";
		if(cnt%n==0) cout<<n;
		else cout<<cnt%n;
	}
	else
	{
		cout<<lie+1<<" ";
		if(cnt%n==0) cout<<1;
		else cout<<n-cnt%n+1;
	}
	return 0;
}