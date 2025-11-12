#include<bits/stdc++.h>
using namespace std;
int n,m,s[101],k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
		if(i==1)k=s[i];
	}
	sort(s+1,s+m*n+1);
	for(int i=n*m;i>=1;i--)
	{
		if(s[i]==k)
		{
			if((m*n-i+1)%n==0&&((m*n-i+1)/n)%2==1)cout<<(m*n-i+1)/n<<" "<<n;
			else if((m*n-i+1)%n==0&&((m*n-i+1)/n)%2==0)cout<<(m*n-i+1)/n<<" "<<1;
			else if(((m*n-i+1)/n+1)%2==0)cout<<(m*n-i+1)/n+1<<" "<<n-(m*n-i+1)%n+1;
			else cout<<(m*n-i+1)/n+1<<" "<<(m*n-i+1)%n;
			break;
		}
	}
	return 0;
}