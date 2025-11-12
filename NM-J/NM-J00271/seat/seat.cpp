#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	
	int main()",stdout);
	int n,m;
	cin>>n>>m;
	int a[100];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int b=1;
	for(int i=1;i<n*m;i++)
	{
		if(a[i]>=a[0])
		{
			b++;
		}
	}
	int c=b/n;
	int r;
	if(c%2==1)
	{
		r=b-(b-n*c);
	}
	else
	{
		r=b-n*c;
	}
	cout<<c<<" "<<r;

	return 0;
}
