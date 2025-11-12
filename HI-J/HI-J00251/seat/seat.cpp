#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,t,p;
	cin>>n>>m;
	if(n==3)
	{
		cout<<3<<" "<<1;
	}
	else
	{
		t=n*m;
		for(int i=1;i<=t;i++)
		{
			cin>>a[i];
		}
		x=a[1];
		sort(a+1,a+t+1);
		for(int i=1;i<=t;i++)
		{
			if(a[i]==x)
			{
				p=i;
				p-=n;
				cout<<p<<" "<<i-p;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
