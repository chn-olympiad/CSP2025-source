#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ccf,rj,cs;
	cin>>n>>m;
	int c[n*m]; 
	for(int i=1;i<=n*m;i++)
	{
		cin>>c[i];
	}
	int r=c[1];
	sort(c+1,c+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(c[i]==r)
		{
			ccf=n*m-i+1;
		}
	}
	rj=ccf/n;
	if(ccf%n!=0)
	{
		if(rj%2==0) cout<<rj+1<<" "<<ccf%n;
		else cout<<rj+1<<" "<<n-ccf%n+1;
	}
	else
	{
		if(rj%2!=0) cout<<rj<<" "<<n;
		else cout<<rj<<" "<<'1';
	}
	return 0;
}
