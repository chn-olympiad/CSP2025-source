#include<bits/stdc++.h>
using namespace std;
int n,m,a,s,k=1,s1,s2;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a;
		if(a>s)
		{
			k++;
		}
	}
	s1=ceil(1.0*k/n);
	s=k%n;
	if(s!=0)
	{
		if(s1%2==0)
			s2=n-s+1;
		else
			s2=s;
	}
	else
	{
		if(s1%2==0)
			s2=1;
		else
			s2=n;
	}
	cout<<s1<<" "<<s2;
	return 0;
}
