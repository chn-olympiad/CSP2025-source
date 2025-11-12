#include<bits/stdc++.h>
using namespace std;
int a[1002];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,cnt;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1); 
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			cnt=n*m-i+1;
		}
	}
	if(cnt%n==0)
	{
		if((cnt/n)%2==0)
		{
			cout<<cnt/n<<" "<<1;
		}
		else{
			cout<<cnt/n<<" "<<n;
		}
	}
	else{
		if((cnt/n)%2==1)
		{
			cout<<cnt/n+1<<" "<<n-cnt%n+1;
		}
		else{
			cout<<cnt/n+1<<" "<<cnt%n;
		}
	}
}
