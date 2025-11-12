#include<bits/stdc++.h>
using namespace std;
long long a,b,n,m,s,ans1=1,ans2=1,o;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(long long i=1;i<n*m;i++)
	{
		cin>>b;
		if(b>a)
		{
			s++;
		}
	}
	while(s>0)
	{
		s--;
		if(!o)
		{
			ans2++;
		}
		else
		{
			ans2--;
		}
		if(ans2>n)
		{
			ans1++;
			ans2=n;
			o=1;
		}
		if(ans2<1)
		{
			ans1++;
			ans2=1;
			o=0;
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}