#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c[n*m+1];
	for(int i=1;i<=n*m;i++)cin>>c[i];
	int rc=c[1];
//	cout<<rc<<endl;
	sort(c+1,c+n*m+1,greater<int>());
	int x;
	for(int i=1;i<=n*m;i++)
	{
		if(c[i]==rc)
		{
			x=i;
			break;
		}
	}
//	cout<<x<<endl;
	if(x%n==0)
	{
//		cout<<1<<endl;
		cout<<x/n<<" ";
		if((x/n)%2==1)cout<<m<<endl;
		else cout<<1<<endl;
		return 0;
	}
	cout<<x/n+1<<" ";
	if((x/n)%2==1)cout<<n-x%n+1<<endl;
	else cout<<x%n<<endl;
	return 0;
}

