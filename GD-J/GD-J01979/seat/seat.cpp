#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,cnt,n1=1,m1=1;
bool f=false;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=2;i<=n*m;++i)
	{
		cin>>y;
		if(y>x)
		{
			cnt++;
		}
	}
	while(cnt--)
	{
		if(f)
		{
			m1++;
			f=false;
		}
		else if(m1%2==1)
		{
			n1++;
			if(n1==n) f=true;
		}
		else
		{
			n1--;
			if(n1==1) f=true;
		}
	}
	cout<<m1<<" "<<n1<<"\n";
	return 0;
}
